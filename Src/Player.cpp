#include <Player.hpp>
#include "Physic.hpp"

Player::Player()
{
    numFootContacts = 0;
    playerAnim.reserve(animationCapacity);

    for(int i = 0;i < animationCapacity ;i++)
    {
        playerAnim[i] = sf::IntRect(i * 256 , 0.0f, 256.0f, 256.0f);
        playerAnim.push_back(playerAnim[i]);
    }
}

void Player::move(sf::Keyboard::Key key)
{

    b2Vec2 vel = body->GetLinearVelocity();

    if (key == sf::Keyboard::D)
    {
        vel.x = 5.0f;
        if(sprite.getScale().x <= -0.8f)
        {
            sprite.scale(-1.0f,1.0f);
        }
    }
    if (key == sf::Keyboard::A)
    {
        vel.x = -5.0f;
        if(sprite.getScale().x >= 0.8f)
        {
            sprite.scale(-1.0f,1.0f);
        }
    }
    body->SetLinearVelocity(vel);
}

void Player::jump()
{
    if(numFootContacts > 1)
    {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = -8.0f;
        body->SetLinearVelocity(vel);
    }
    if(numFootContacts == 1)
    {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = -8.0f;
        body->SetLinearVelocity(vel);
        numFootContacts--;
    }
}

void Player::Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager)
{
    auto &texture = graphicsManager.loadTexture(path);
    sprite.setTexture(texture);
    sprite.setTextureRect(playerAnim[0]);
    sprite.setScale(0.8f,0.8f);
    sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height/ 2);

    sprite.setPosition(960.f, 540.f);

    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(sprite.getPosition().x / 100.0f, sprite.getPosition().y / 100.0f); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    myBodyDef.fixedRotation = true;
    body = physicsManager.createBody(myBodyDef);

    boxShape.SetAsBox((sprite.getTextureRect().width / 100.0f) / 4.0f, (sprite.getTextureRect().height / 100.0f) / 2.8f);
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1;
    body->CreateFixture(&fixtureDef);
    body->SetGravityScale(2.0f);

    //Foot sensor fixture
    footShape.SetAsBox((sprite.getTextureRect().width / 100.0f) / 2.0f, (sprite.getTextureRect().height / 100.0f) / 2.0f, b2Vec2(0, 0), 0);
    footFixtureDef.shape = &footShape;
    footFixtureDef.isSensor = true;
    footFixtureDef.userData = ((void*)1);
    footSensor = body->CreateFixture(&footFixtureDef);
}

void Player::Render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(sprite);
}

void Player::Update(float deltaTime)
{
    sprite.setPosition(body->GetPosition().x * 100, body->GetPosition().y * 100);
    loopTime += deltaTime;
    std::cout<<playerAnimIndex<<"\n";

    if(loopTime >= 0.16f)
    {
        sprite.setTextureRect(playerAnim[playerAnimIndex]);
        playerAnimIndex++;
        loopTime = 0;
    }
    if(playerAnimIndex == animationCapacity)
    {
        std::cout<<"PLAYER ANIM INDEX = 0" << "\n";
        playerAnimIndex = 0;
    }
}

void Player::stopMoving()
{
    body->SetLinearVelocity(b2Vec2(0.0f,body->GetLinearVelocity().y));
}

sf::Vector2f Player::GetPosition()
{
    return sprite.getPosition();
}

ContactListener::ContactListener(Player &player) : player(player)
{

}

void ContactListener::BeginContact(b2Contact *contact)
{
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if (fixtureUserData == (void*)2)
    {
        player.numFootContacts = 2;
    }

    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if (fixtureUserData == (void*)2)
    {
        player.numFootContacts = 2;
    }
}

void ContactListener::EndContact(b2Contact *contact)
{
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        player.numFootContacts = 1;
    }

    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        player.numFootContacts = 1;
    }
}




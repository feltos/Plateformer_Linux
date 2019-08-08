#include <Player.hpp>
#include "Physic.hpp"

Player::Player()
{
    numFootContacts = 0;
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
    sprite.setTextureRect(sf::IntRect(0.0f,0.0f,256.0f,256.0f));
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

void Player::Update()
{
    sprite.setPosition(body->GetPosition().x * 100, body->GetPosition().y * 100);
}

std::vector<sf::IntRect> Player::PlayerAnim()
{
    animation.reserve(animationCapacity);
    float rectLeftSize = 0;
    for(int i = 0;i < animationCapacity;i++)
    {
        animation[i] = sf::IntRect(animation[i].left + rectLeftSize,0.0f,256.0f,256.0f);
        animation.push_back(animation[i]);
        rectLeftSize += 256.0f;
    }
    return animation;
}

void Player::SetSprite(sf::IntRect intRect)
{
    sprite.setTextureRect(intRect);
}

void Player::stopMoving()
{
    body->SetLinearVelocity(b2Vec2(0.0f,body->GetLinearVelocity().y));
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




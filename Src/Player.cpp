#include <Player.hpp>
#include "Physic.hpp"

Player::Player()
{
    numFootContacts = 0;
}

void Player::move(sf::Keyboard::Key key, float deltaTime)
{

    b2Vec2 vel = body->GetLinearVelocity();
    std::cout<<"KEY PRESSED";

    if (key == sf::Keyboard::D)
    {
        vel.x = 5.0f;
        if(sprite.getScale().x <= -1.0f)
        {
            sprite.scale(-1.0f,1.0f);
        }
    }
    if (key == sf::Keyboard::A)
    {
        vel.x = -5.0f;
        if(sprite.getScale().x >= 1.0f)
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
        vel.y = -10.0f;
        body->SetLinearVelocity(vel);
    }
    if(numFootContacts == 1)
    {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = -10.0f;
        body->SetLinearVelocity(vel);
        numFootContacts--;
    }
}

void Player::Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager)
{
    auto &texture = graphicsManager.loadTexture(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(960.f, 540.f);

    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(sprite.getPosition().x / 100.0f, sprite.getPosition().y / 100.0f); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    myBodyDef.fixedRotation = true;
    body = physicsManager.createBody(myBodyDef);

    boxShape.SetAsBox(((texture.getSize().x / 100.0f) / 2.0f), (texture.getSize().y / 100.0f) / 2.0f);
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1;
    body->CreateFixture(&fixtureDef);

    //Foot sensor fixture
    footShape.SetAsBox((texture.getSize().x / 100.0f / 2.0f), (texture.getSize().y / 100.0f) / 2.0f, b2Vec2(0, 1), 0);
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




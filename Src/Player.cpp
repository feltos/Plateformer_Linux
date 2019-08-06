#include <Player.hpp>
#include "Physic.hpp"

void Player::move(sf::Keyboard::Key key)
{
    b2Vec2 vel = body->GetLinearVelocity();

    if (key == sf::Keyboard::D)
    {
        vel.x = 3.0f;
    }
    if (key == sf::Keyboard::A)
    {
        vel.x = -3.0f;
    }
    body->SetLinearVelocity(vel);
}

void Player::jump()
{
    if(numFootContacts >= 1)
    {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = -7.0f;
        body->SetLinearVelocity(vel);
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
    boxShape.SetAsBox(0.3f,0.3f,b2Vec2(0,-2),0);
    fixtureDef.isSensor = true;
    b2Fixture* footSensorFixture = body->CreateFixture(&fixtureDef);
    footSensorFixture->SetUserData((void*)1);
}

void Player::Render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(sprite);
}

void Player::Update()
{
    sprite.setPosition(body->GetPosition().x * 100, body->GetPosition().y * 100);

}

Player::Player()
{
    numFootContacts = 0;
}

void ContactListener::BeginContact(b2Contact *contact)
{
    printf("BEGIN CONTACT");
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        printf("BEGIN FIXTURE A");
        player.numFootContacts++;
    }

    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        printf("BEGIN FIXTURE B");
        player.numFootContacts++;
    }
}

void ContactListener::EndContact(b2Contact *contact)
{
    printf("END CONTACT");
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        player.numFootContacts--;
    }

    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        player.numFootContacts--;
    }
}

ContactListener::ContactListener(Player &player) : player(player)
{

}



#include <Player.hpp>
#include "Physic.hpp"

Player::Player()
{
    nmbOfJump = 0;

    IdleAnim.reserve(32);
    RunAnim.reserve(18);
    JumpAnim.reserve(8);

    for(int i = 0;i < 32; i++)
    {
        IdleAnim[i] = sf::IntRect(i * 281 , 0.0f, 281.0f, 251.0f);
        IdleAnim.push_back(IdleAnim[i]);
    }
    for(int i = 0;i < 18 ;i++)
    {
        RunAnim[i] = sf::IntRect(i * 240 , 0.0f, 240.0f, 245.0f);
        RunAnim.push_back(RunAnim[i]);
    }
    for(int i = 0;i < 8 ;i++)
    {
        JumpAnim[i] = sf::IntRect(i * 136 , 0.0f, 136.0f, 235.0f);
        JumpAnim.push_back(JumpAnim[i]);
    }
}

void Player::move(sf::Keyboard::Key key)
{
    b2Vec2 vel = body->GetLinearVelocity();

    if (key == sf::Keyboard::D)
    {
        vel.x = 10.0f;
        if(sprite.getScale().x <= -0.8f)
        {
            sprite.scale(-1.0f,1.0f);
        }
    }
    if (key == sf::Keyboard::A)
    {
        vel.x = -10.0f;
        if(sprite.getScale().x >= 0.8f)
        {
            sprite.scale(-1.0f,1.0f);
        }
    }
    body->SetLinearVelocity(vel);
}

void Player::jump()
{
    if(nmbOfJump > 1)
    {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = -8.0f;
        body->SetLinearVelocity(vel);
    }
    if(nmbOfJump == 1)
    {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = -8.0f;
        body->SetLinearVelocity(vel);
        nmbOfJump--;
    }
}

void Player::Init( GraphicsManager &graphicsManager, PhysicsManager &physicsManager)
{
    idleTexture = graphicsManager.loadTexture("../Textures/ShantaeAnim/ShantaeIdle.png");
    runTexture = graphicsManager.loadTexture("../Textures/ShantaeAnim/ShantaeRun.png");
    jumpTexture = graphicsManager.loadTexture("../Textures/ShantaeAnim/ShantaeJump.png");

    sprite.setTexture(idleTexture);
    sprite.setTextureRect(IdleAnim[0]);
    sprite.setScale(1.0f,1.0f);
    sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height/ 2);

    sprite.setPosition(960.f, 540.f);

    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(sprite.getTextureRect().width / 100.0f, sprite.getTextureRect().height / 100.0f); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    myBodyDef.fixedRotation = true;
    body = physicsManager.createBody(myBodyDef);

    boxShape.SetAsBox((sprite.getTextureRect().width / 100.0f) / 4.0f, (sprite.getTextureRect().height / 100.0f) / 2.0f);
    fixtureDef.shape = &boxShape;
    fixtureDef.friction = 0;
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
    std::cout<<playerAnimIndex<<"\n";


    sprite.setPosition(body->GetPosition().x * 100, body->GetPosition().y * 100);

    switch (state)
    {
        case AnimState::IDLE :
        {
            loopTime += deltaTime;
            if(loopTime >= 0.025f)
            {
                sprite.setTexture(idleTexture);
                sprite.setTextureRect(IdleAnim[playerAnimIndex]);

                playerAnimIndex++;
                loopTime = 0;
            }
            if(playerAnimIndex == IdleAnim.size())
            {
                playerAnimIndex = 0;
            }
            if(!isGrounded)
            {
                playerAnimIndex = 0;
                state = AnimState::JUMP;
            }
            if(isGrounded && body->GetLinearVelocity().x != 0.0f)
            {
                playerAnimIndex = 0;
                state = AnimState::RUN;
            }
            break;
        }
        case AnimState::RUN :
        {
            loopTime += deltaTime;
            if(loopTime >= 0.025f)
            {
                sprite.setTexture(runTexture);
                sprite.setTextureRect(RunAnim[playerAnimIndex]);

                playerAnimIndex++;
                loopTime = 0;
            }
            if(playerAnimIndex == RunAnim.size())
            {
                playerAnimIndex = 0;
            }
            if(isGrounded && body->GetLinearVelocity() == b2Vec2(0.0f,0.0f))
            {
                playerAnimIndex = 0;
                state = AnimState::IDLE;
            }
            if(!isGrounded)
            {
                playerAnimIndex = 0;
                state = AnimState::JUMP;
            }
            break;
        }
        case AnimState::JUMP :
        {
            loopTime += deltaTime;
            if(loopTime >= 0.025f)
            {
                sprite.setTexture(jumpTexture);
                sprite.setTextureRect(JumpAnim[playerAnimIndex]);

                playerAnimIndex++;
                loopTime = 0;
            }
            if(playerAnimIndex == JumpAnim.size())
            {
                playerAnimIndex = 0;
            }
            if(isGrounded && body->GetLinearVelocity() == b2Vec2(0.0f,0.0f))
            {
                playerAnimIndex = 0;
                state = AnimState::IDLE;
            }
            if(isGrounded && body->GetLinearVelocity().x != 0.0f)
            {
                playerAnimIndex = 0;
                state = AnimState::RUN;
            }
            break;
        }
    }

}

void Player::stopMoving()
{
    if(isGrounded)
    {
        body->SetLinearVelocity(b2Vec2(0.0f,body->GetLinearVelocity().y));
    }

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
        player.nmbOfJump = 2;
        player.isGrounded = true;
    }

    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if (fixtureUserData == (void*)2)
    {
        player.nmbOfJump = 2;
        player.isGrounded = true;
    }
}

void ContactListener::EndContact(b2Contact *contact)
{
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        player.nmbOfJump = 1;
        player.isGrounded = false;
    }

    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ( fixtureUserData == (void*)2)
    {
        player.nmbOfJump = 1;
        player.isGrounded = false;
    }
}




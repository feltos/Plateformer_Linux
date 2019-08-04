#include "Physic.hpp"

Bodies::Bodies()
{
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(0, 20); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    b2Body* dynamicBody = physicsManager->GetWorld().CreateBody(&myBodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(1,1);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    dynamicBody->CreateFixture(&boxFixtureDef);
}

b2World PhysicsManager::GetWorld()
{
    return *m_world;
}

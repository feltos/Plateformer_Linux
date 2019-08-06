#include "Physic.hpp"


PhysicsManager::PhysicsManager(Player& player):contactListener(player)
{
    m_world = std::make_unique<b2World>(b2Vec2( 0.0f,9.81f));
}

b2Body *PhysicsManager::createBody(b2BodyDef& bodyDef)
{
    b2Body* body = m_world->CreateBody(&bodyDef);
    return body;
}

void PhysicsManager::Update()
{
    m_world->SetContactListener(&contactListener);
    m_world->Step(1.0f/60.0f,8,3);
}



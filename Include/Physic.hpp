#pragma once

#include "Box2D/Box2D.h"
#include "Player.hpp"

class PhysicsManager
{

public:

    explicit PhysicsManager(Player& player);

    b2Body* createBody(b2BodyDef& bodyDef);
    void Update();

private:

    ContactListener contactListener;

protected:

    b2Body* m_groundBody = nullptr;
    std::unique_ptr<b2World> m_world = nullptr;

};




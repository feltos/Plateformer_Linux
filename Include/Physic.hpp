#pragma once

#include "Box2D/Box2D.h"

class PhysicsManager
{
public:

    b2World GetWorld();

private:

protected:

    b2World* m_world;
    b2Body* m_groundBody;

};

class Bodies
{
public:

    Bodies();

private:

    PhysicsManager* physicsManager;
};
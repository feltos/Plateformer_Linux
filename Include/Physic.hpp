#pragma once

#include "Box2D/Box2D.h"

class PhysicsManager
{
public:
    PhysicsManager();

public:

    b2Body* createBody(b2BodyDef& bodyDef);
    void Update();

private:


protected:

    b2Body* m_groundBody = nullptr;
    std::unique_ptr<b2World> m_world = nullptr;

};




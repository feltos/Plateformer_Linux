#pragma once

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Physic.hpp"
#include "Graphics.hpp"
#include "vector"

class Platform
{
public:

    sf::Sprite
    Init(GraphicsManager &graphicsManager, PhysicsManager &physicsManager, sf::Vector2f position, sf::String path);
    void Render(sf::RenderWindow& renderWindow);

private:

    b2BodyDef myBodyDef;
    b2Body* body = nullptr;
    sf::Sprite sprite;

    b2PolygonShape boxShape;
    b2FixtureDef fixtureDef;

protected:


};
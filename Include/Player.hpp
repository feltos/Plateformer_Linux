#pragma once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Physic.hpp"
#include "Graphics.hpp"
#include "iostream"

class Player
{
public:

    void move(sf::Keyboard::Key key);
    void jump();
    void Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager);
    void Render(sf::RenderWindow& renderWindow);
    void Update();

private:

    b2BodyDef myBodyDef;
    b2Body* body = nullptr;
    sf::Sprite sprite;

    b2PolygonShape boxShape;
    b2FixtureDef fixtureDef;
    sf::RectangleShape shape;
};
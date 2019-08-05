#pragma once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Physic.hpp"
#include "Graphics.hpp"

class Player
{
public:

    explicit Player(PhysicsManager &physicsManager, GraphicsManager &graphicsManager);

    void move(sf::Keyboard::Key key);
    void jump();
    void Init(std::string path);
    void Render(sf::RenderWindow& renderWindow);
    void Update();

private:

    b2BodyDef myBodyDef;
    b2Body* body = nullptr;
    PhysicsManager& physicsManager;
    GraphicsManager& graphicsManager;
    sf::Sprite sprite;
};
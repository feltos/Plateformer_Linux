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
    void Render(sf::RenderWindow &renderWindow, sf::Sprite sprite);

private:

protected:


};
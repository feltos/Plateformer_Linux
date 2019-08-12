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
    CreateSprite(GraphicsManager &graphicsManager, PhysicsManager &physicsManager, sf::Vector2f position, sf::String path);
    void Render(sf::RenderWindow &renderWindow, std::vector<sf::Sprite> sprite);
    void Init(GraphicsManager &graphicsManager, PhysicsManager &physicsManager);


private:

    std::vector<sf::Sprite> spriteVector;
public:
    const std::vector<sf::Sprite> &getSpriteVector() const;

protected:


};
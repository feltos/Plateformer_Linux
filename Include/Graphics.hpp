#pragma  once

#include "SFML/Graphics.hpp"
#include "string"
#include "vector"
#include "SFML/Graphics/View.hpp"
#include "iostream"
#include "SFML/Graphics/RenderWindow.hpp"

class GraphicsManager
{
public:

    GraphicsManager();

    sf::Texture & loadTexture(std::string path);
    void Scrolling(sf::Vector2f playerPos, sf::RenderWindow &renderWindow);

private:

    std::vector<sf::Texture> texturesList;

};
#pragma  once

#include "SFML/Graphics.hpp"
#include "string"
#include "vector"

class GraphicsManager
{
public:

    GraphicsManager();


    sf::Texture & loadTexture(std::string path);
    sf::Sprite createSprite(std::string path);
    void setSpritePosition(sf::Sprite sprite, float posX, float posY);

private:

    std::vector<sf::Texture> texturesList;
};
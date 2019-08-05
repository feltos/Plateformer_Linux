#pragma  once

#include "SFML/Graphics.hpp"
#include "string"
#include "vector"

class GraphicsManager
{
public:

    GraphicsManager();

    sf::Texture & loadTexture(std::string path);

private:

    std::vector<sf::Texture> texturesList;
};
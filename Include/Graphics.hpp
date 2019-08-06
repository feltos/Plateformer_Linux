#pragma  once

#include "SFML/Graphics.hpp"
#include "string"
#include "vector"
#include "SFML/Graphics/View.hpp"

class GraphicsManager
{
public:

    GraphicsManager();

    sf::Texture & loadTexture(std::string path);

    void ZoomViewport(float factor);

private:

    std::vector<sf::Texture> texturesList;
};
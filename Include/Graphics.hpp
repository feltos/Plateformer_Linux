#pragma  once

#include "SFML/Graphics.hpp"
#include "string"
#include "vector"
#include "SFML/Graphics/View.hpp"
#include "iostream"

class GraphicsManager
{
public:

    GraphicsManager();

    sf::Texture & loadTexture(std::string path);

    static void ZoomViewport(float factor, sf::View view);

private:

    std::vector<sf::Texture> texturesList;
};
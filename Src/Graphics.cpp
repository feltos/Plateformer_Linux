#include "Graphics.hpp"

sf::Texture & GraphicsManager::loadTexture(std::string path)
{

    texturesList.push_back(sf::Texture());
    auto &texture = texturesList.back();

    if(!texture.loadFromFile(path))
    {
        printf("Can't load texture");
    }
    texture.setSmooth(true);
    return texture;
}

GraphicsManager::GraphicsManager()
{
    texturesList.reserve(8);
}

void GraphicsManager::ZoomViewport(float factor, sf::View view)
{
    std::cout<<factor <<"\n";
    view.zoom(factor);
}



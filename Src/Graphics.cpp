#include "Graphics.hpp"

sf::Texture & GraphicsManager::loadTexture(std::string path)
{

    texturesList.push_back(sf::Texture());
    auto &texture = texturesList.back();

    if(!texture.loadFromFile(path))
    {
        printf("Can't load texture");
    }

    return texture;
}

GraphicsManager::GraphicsManager()
{
    texturesList.reserve(8);
}



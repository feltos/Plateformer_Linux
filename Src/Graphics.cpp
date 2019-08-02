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

sf::Sprite GraphicsManager::createSprite(std::string path)
{
    sf::Sprite sprite;
    auto &texture = loadTexture(path);
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getTexture()->getSize().x /2 ,sprite.getTexture()->getSize().y /2);
    sprite.setPosition(960.f,540.f);
    return sprite;
}

void GraphicsManager::setSpritePosition(sf::Sprite sprite, float posX, float posY)
{
    sprite.setPosition(posX,posY);
}

GraphicsManager::GraphicsManager()
{
    texturesList.reserve(8);
}



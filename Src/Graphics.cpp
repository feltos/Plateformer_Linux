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

void GraphicsManager::Scrolling(sf::Vector2f playerPos, sf::RenderWindow &renderWindow)
{
    auto offset = sf::Vector2f(100.0f,100.0f);
    auto view = renderWindow.getView();
    view.setCenter(playerPos + offset);
    renderWindow.setView(view);
}



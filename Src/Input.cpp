#include "Input.hpp"

void InputManager::addKeyPressed(sf::Keyboard::Key newKey)
{
    actualKeyPressed.push_back(newKey);
}

void InputManager::clearKeyPressed()
{
    actualKeyPressed.clear();
}

std::vector<sf::Keyboard::Key> &InputManager::getActualKeyPressed()
{
    return actualKeyPressed;
}

void InputManager::move(sf::Sprite sprite, sf::Keyboard::Key key)
{
    if(key == sf::Keyboard::D)
    {
        sprite.move(1, 0.0f);
    }
   if(key == sf::Keyboard::A)
   {
       sprite.move(-1,0.0f);
   }
}

void InputManager::jump(sf::Sprite sprite)
{
    if(sf::Keyboard::Space)
    {
        sprite.move(0.0f,sprite.getPosition().y - 10);
    }

}





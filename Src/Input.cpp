#include "Input.hpp"

std::vector<sf::Keyboard::Key> InputManager::GetKeyPressedList()
{
    return actualKeyPressed;
}

void InputManager::addKeyPressed(sf::Keyboard::Key newKey)
{
    actualKeyPressed.push_back(newKey);
}

void InputManager::clearKeyPressed()
{
    actualKeyPressed.clear();
}



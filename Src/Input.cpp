#include "Input.hpp"

std::queue<sf::Keyboard::Key> InputManager::GetKeyPressedList()
{
    return actualKeyPressed;
}

void InputManager::addKeyPressed(sf::Keyboard::Key newKey)
{
    actualKeyPressed.push(newKey);
}

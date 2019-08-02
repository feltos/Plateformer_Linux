#pragma  once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "queue"

class InputManager
{
public:

    std::queue<sf::Keyboard::Key> GetKeyPressedList();
    void addKeyPressed(sf::Keyboard::Key newKey);

private:

    std::queue<sf::Keyboard::Key> actualKeyPressed;
};

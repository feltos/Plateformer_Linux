#pragma  once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "vector"

class InputManager
{
public:

    std::vector<sf::Keyboard::Key> GetKeyPressedList();
    void addKeyPressed(sf::Keyboard::Key newKey);
    void clearKeyPressed();

private:

    std::vector<sf::Keyboard::Key> actualKeyPressed;
};

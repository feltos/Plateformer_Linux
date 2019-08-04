#pragma  once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics.hpp"
#include "vector"

class InputManager
{
public:

    void addKeyPressed(sf::Keyboard::Key newKey);
    void clearKeyPressed();

private:

    std::vector<sf::Keyboard::Key> actualKeyPressed;

public:

    std::vector<sf::Keyboard::Key> &getActualKeyPressed();
    void move(sf::Sprite sprite,sf::Keyboard::Key key);
    void jump(sf::Sprite sprite);

public:



};

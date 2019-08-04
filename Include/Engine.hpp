#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Input.hpp"
#include "iostream"
#include "Graphics.hpp"
#include "Sound.hpp"

class Engine
{

public:
    explicit  Engine(sf::RenderWindow &renderWindow);
    void Init();
    void Loop();
    void checkKeyPressed(sf::Sprite sprite);
private:

    sf::RenderWindow &renderWindow;
    InputManager inputManager;
    GraphicsManager graphicsManager;
    SoundManager soundManager;

};
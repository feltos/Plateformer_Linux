#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "iostream"
#include "Graphics.hpp"
#include "Sound.hpp"
#include "Player.hpp"
#include "Platform.hpp"

class Engine
{

public:

    explicit Engine(sf::RenderWindow &renderWindow);
    void Init();
    void Loop();
    void ZoomViewport(float delta);
    sf::Clock clock;

private:

    sf::RenderWindow &renderWindow;
    SoundManager soundManager;
    GraphicsManager graphicsManager;
    PhysicsManager physicsManager;
    Player player;
    Platform platforms;
};
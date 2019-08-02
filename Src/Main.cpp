#include "SFML/Window.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Input.hpp"
#include "iostream"
#include "Graphics.hpp"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(1920,1080),"MyWindow",sf::Style::Default);

    InputManager inputManager;
    GraphicsManager graphicsManager;

    sf::Sprite sprite = graphicsManager.createSprite("../Textures/BrickGrassTexture.jpg");

    sf::Sprite sprite1 = graphicsManager.createSprite("../Textures/PaperTexture.jpg");

    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                inputManager.addKeyPressed(event.key.code);
            }
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        window.clear();
        window.draw(sprite);
        window.draw(sprite1);
        window.display();
        inputManager.GetKeyPressedList().clear();
    }

    return 0;
}

#include <Engine.hpp>

void Engine::Init() {

}

void Engine::Loop()
{
    player.Init("../Textures/Player.png",graphicsManager,physicsManager);
    auto ground = platforms.Init(graphicsManager, physicsManager, sf::Vector2f(960.0f, 1180.0f),"../Textures/Ground.png");

    sf::Sound footSteps = soundManager.createSound("../Sounds/FootSteps.wav");

    while (renderWindow.isOpen()) {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (renderWindow.pollEvent(event)) {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed) {
                renderWindow.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                auto key = event.key.code;

                if (key == sf::Keyboard::D || key == sf::Keyboard::A) {
                    player.move(key);
                }
                if (key == sf::Keyboard::Space) {
                    player.jump();
                }
            }

            if(event.type = sf::Event::MouseWheelMoved)
            {
                graphicsManager.ZoomViewport();
            }
        }
        physicsManager.Update();
        player.Update();
        renderWindow.clear();
        player.Render(renderWindow);
        renderWindow.draw(ground);
        renderWindow.display();
    }
}

Engine::Engine(sf::RenderWindow &renderWindow) : renderWindow(renderWindow), physicsManager(player)
{

}







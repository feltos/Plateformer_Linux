
#include <Engine.hpp>

Engine::Engine(sf::RenderWindow &renderWindow) : renderWindow(renderWindow), physicsManager(player)
{

}

void Engine::Init()
{

}

void Engine::Loop()
{
    player.Init(graphicsManager,physicsManager);
    platforms.Init(graphicsManager, physicsManager);

    sf::Sound footSteps = soundManager.createSound("../Sounds/FootSteps.wav");
    sf::Clock clock;

    while (renderWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                auto key = event.key.code;

                if (key == sf::Keyboard::D || key == sf::Keyboard::A)
                {
                    player.move(key);
                }

                if (key == sf::Keyboard::Space)
                {
                    player.jump();
                }
            }
            if(event.type == sf::Event::KeyReleased)
            {
                auto key = event.key.code;
                if (key == sf::Keyboard::D || key == sf::Keyboard::A)
                {
                    player.stopMoving();
                }
            }

            if(event.type == sf::Event::MouseWheelScrolled)
            {
                float delta = event.mouseWheelScroll.delta;
                ZoomViewport(delta);
            }
        }
        physicsManager.Update();
        player.Update(deltaTime.asSeconds());
        graphicsManager.Scrolling(player.GetPosition(),renderWindow);
        renderWindow.clear();
        player.Render(renderWindow);
        platforms.Render(renderWindow,platforms.getSpriteVector());
        renderWindow.display();
    }
}

void Engine::ZoomViewport(float delta)
{
    auto view = renderWindow.getView();
    float factor = 0;

    if (delta <= -1.0f)
    {
        factor = 2.0f;
        view.zoom(factor);
    }
    if(delta >= 1.0f)
    {
        factor = 0.5f;
        view.zoom(factor);
    }
    renderWindow.setView(view);
}







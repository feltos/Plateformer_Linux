
#include <Engine.hpp>

Engine::Engine(sf::RenderWindow &renderWindow) : renderWindow(renderWindow), physicsManager(player)
{

}

void Engine::Init()
{

}

void Engine::Loop()
{
    player.Init("../Textures/spriteStrip.png",graphicsManager,physicsManager);
    sf::Sprite ground = platforms.Init(graphicsManager, physicsManager, sf::Vector2f(960.0f, 1180.0f),"../Textures/Ground.png");
    sf::Sprite platform1 = platforms.Init(graphicsManager, physicsManager, sf::Vector2f(1900.0f, 600.0f), "../Textures/Platform.png");
    sf::Sprite platform2 = platforms.Init(graphicsManager, physicsManager, sf::Vector2f(200.0f, 600.0f), "../Textures/Platform.png");
    sf::Sprite platform3 = platforms.Init(graphicsManager, physicsManager, sf::Vector2f(1000.0f, 600.0f), "../Textures/Platform.png");

    sf::Sound footSteps = soundManager.createSound("../Sounds/FootSteps.wav");

    auto anim = player.PlayerAnim();
    int animIterator = 0;
    float timeLoop = 0.5f;

    while (renderWindow.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            sf::Time time = clock.getElapsedTime();
            float deltaTime = time.asSeconds();

            ///////CHANGE ANIMATION/////////////
            std::cout<<deltaTime<< "\n";
            if(deltaTime >= timeLoop)
            {
                animIterator++;
                clock.restart();
            }
            if(animIterator >= anim.size())
            {
                animIterator = 0;
            }
            /////////////////////////////

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
        player.Update();
        renderWindow.clear();
        player.SetSprite(anim[animIterator]);
        player.Render(renderWindow);
        platforms.Render(renderWindow,ground);
        platforms.Render(renderWindow, platform1);
        platforms.Render(renderWindow,platform2);
        platforms.Render(renderWindow,platform3);
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







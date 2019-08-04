
#include <Engine.hpp>

void Engine::Init()
{

}

void Engine::Loop()
{
    sf::Sprite sprite = graphicsManager.createSprite("../Textures/BrickGrassTexture.jpg");

    sf::Sprite sprite1 = graphicsManager.createSprite("../Textures/PaperTexture.jpg");

    sf::Sound footSteps = soundManager.createSound("../Sounds/FootSteps.wav");

    sf::Clock timer;

    while (renderWindow.isOpen())
    {
        inputManager.getActualKeyPressed().clear();
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
               // inputManager.move(sprite1, event.key.code);
                //inputManager.addKeyPressed(event.key.code);

                if(event.key.code == sf::Keyboard::D)
                {
                    sprite1.move(2, 0.0f);
                    footSteps.play();
                }
                if(event.key.code == sf::Keyboard::A)
                {
                    sprite1.move(-2, 0.0f);
                    footSteps.play();
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    sprite1.move(0.0f,-10.0f);
                    //inputManager.jump(sprite1);
                }
            }

        }

        //checkKeyPressed(sprite1);
        renderWindow.clear();
        //renderWindow.draw(sprite);
        renderWindow.draw(sprite1);
        renderWindow.display();
    }
}

Engine::Engine(sf::RenderWindow &renderWindow): renderWindow(renderWindow)
{

}

void Engine::checkKeyPressed(sf::Sprite sprite)
{
    //DIDN'T WORK OF COURSE
    for(int i = 0; i < inputManager.getActualKeyPressed().size(); i++)
    {
        if(i == sf::Keyboard::D || i == sf::Keyboard::A)
        {
            //inputManager.move(sprite);
        }
        if(i == sf::Keyboard::Space)
        {
            inputManager.jump(sprite);
        }
    }
}





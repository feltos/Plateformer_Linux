#include "SFML/Window.hpp"
#include "Engine.hpp"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(1920,1080),"MyWindow",sf::Style::Default);
    Engine engine(window);
    engine.Init();
    engine.Loop();
    return 0;
}
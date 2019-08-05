
#include <Platform.hpp>

void Platform::Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager)
{
    auto &texture = graphicsManager.loadTexture(path);
    sprite.setTexture(texture);
    sprite.setScale(2.0f,0.3f);
    sprite.setOrigin(texture.getSize().x /2 ,texture.getSize().y /2);
    sprite.setPosition(960.f,1100.0f);

    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(sprite.getPosition().x/100,sprite.getPosition().y/100); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    body = physicsManager.createBody(myBodyDef);
}

void Platform::Render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(sprite);
}




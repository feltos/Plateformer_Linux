
#include <Platform.hpp>

void Platform::Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager)
{
    auto &texture = graphicsManager.loadTexture(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x /2 ,texture.getSize().y /2);
    sprite.setPosition(700.f,1500.0f);

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(sprite.getPosition().x/100.0f, sprite.getPosition().y/100.0f); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    body = physicsManager.createBody(myBodyDef);

    boxShape.SetAsBox(((texture.getSize().x / 100.0f) / 2.0f), (texture.getSize().y / 100.0f) / 2.0f);
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1;
    body->CreateFixture(&fixtureDef);
}

void Platform::Render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(sprite);
}




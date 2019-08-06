
#include <Platform.hpp>

sf::Sprite
Platform::Init(GraphicsManager &graphicsManager, PhysicsManager &physicsManager, sf::Vector2f position, sf::String path)
{
    auto &texture = graphicsManager.loadTexture(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x /2 ,texture.getSize().y /2);
    sprite.setPosition(position);

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(sprite.getPosition().x/100.0f, sprite.getPosition().y/100.0f); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    myBodyDef.fixedRotation = true;
    body = physicsManager.createBody(myBodyDef);

    boxShape.SetAsBox(((texture.getSize().x / 100.0f) / 2.0f), (texture.getSize().y / 100.0f) / 2.0f);
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1;
    body->CreateFixture(&fixtureDef);

    fixtureDef.userData = (void*)2;

    return sprite;
}

void Platform::Render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(sprite);
}




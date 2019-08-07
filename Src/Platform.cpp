
#include <Platform.hpp>

sf::Sprite
Platform::Init(GraphicsManager &graphicsManager, PhysicsManager &physicsManager, sf::Vector2f position, sf::String path)
{
    sf::Sprite newSprite;

    auto &texture = graphicsManager.loadTexture(path);
    newSprite.setTexture(texture);
    newSprite.setOrigin(texture.getSize().x /2 ,texture.getSize().y /2);
    newSprite.setPosition(position);

    b2BodyDef newBodyDef;
    newBodyDef.type = b2_staticBody;
    newBodyDef.position.Set(newSprite.getPosition().x/100.0f, newSprite.getPosition().y/100.0f); //set the starting position
    newBodyDef.angle = 0; //set the starting angle
    newBodyDef.fixedRotation = true;

    b2Body* newBody;
    newBody = physicsManager.createBody(newBodyDef);

    b2PolygonShape newBoxShape;

    newBoxShape.SetAsBox(((texture.getSize().x / 100.0f) / 2.0f), (texture.getSize().y / 100.0f) / 2.0f);

    b2FixtureDef newFixtureDef;

    newFixtureDef.shape = &newBoxShape;
    newFixtureDef.density = 1;
    newFixtureDef.userData = (void*)2;
    newBody->CreateFixture(&newFixtureDef);

    return newSprite;
}

void Platform::Render(sf::RenderWindow &renderWindow, sf::Sprite sprite)
{
    renderWindow.draw(sprite);
}




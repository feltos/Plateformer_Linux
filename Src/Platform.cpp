
#include <Platform.hpp>

sf::Sprite
Platform::CreateSprite(GraphicsManager &graphicsManager, PhysicsManager &physicsManager, sf::Vector2f position, sf::String path)
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

    spriteVector.push_back(newSprite);

    return newSprite;
}

void Platform::Render(sf::RenderWindow &renderWindow, std::vector<sf::Sprite> sprite)
{
    for(int i = 0; i < spriteVector.size(); i++)
    {
        renderWindow.draw(sprite[i]);
    }
}

const std::vector<sf::Sprite> &Platform::getSpriteVector() const
{
    return spriteVector;
}

void Platform::Init(GraphicsManager &graphicsManager, PhysicsManager &physicsManager)
{
    CreateSprite(graphicsManager, physicsManager, sf::Vector2f(960.0f, 1180.0f),
                                               "../Textures/Ground.png");
    CreateSprite(graphicsManager, physicsManager, sf::Vector2f(1900.0f, 600.0f),
                                                  "../Textures/Platform.png");
    CreateSprite(graphicsManager, physicsManager, sf::Vector2f(200.0f, 600.0f),
                                                  "../Textures/Platform.png");
    CreateSprite(graphicsManager, physicsManager, sf::Vector2f(1000.0f, 600.0f),
                                                  "../Textures/Platform.png");
}




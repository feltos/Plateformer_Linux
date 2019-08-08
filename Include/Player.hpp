#pragma once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Graphics.hpp"
#include "iostream"

class PhysicsManager;

class Player
{
public:

    Player();

    void move(sf::Keyboard::Key key);
    void jump();
    void Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager);
    void Render(sf::RenderWindow& renderWindow);
    void Update();
    void stopMoving();
    int numFootContacts;

    std::vector<sf::IntRect> PlayerAnim();
    void SetSprite(sf::IntRect intRect);


private:

    b2BodyDef myBodyDef;
    b2Body* body = nullptr;
    sf::Sprite sprite;

    b2PolygonShape boxShape;
    b2FixtureDef fixtureDef;

    b2PolygonShape footShape;
    b2Fixture* footSensor = nullptr;
    b2FixtureDef footFixtureDef;
    sf::RectangleShape shape;

    std::vector<sf::IntRect> animation;
    int animationCapacity = 6;
};

class  ContactListener : public  b2ContactListener
{
public:

    ContactListener(Player &player);

    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);

private:

    Player& player;

protected:

};
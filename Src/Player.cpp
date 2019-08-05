#include <Player.hpp>


void Player::move(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::D) {
        sprite.move(1, 0.0f);
        printf("D pressed");
    }
    if (key == sf::Keyboard::A) {
        sprite.move(-1, 0.0f);
        printf("A pressed");
    }
}

void Player::jump() {
    sprite.move(0.0f, -10.0f);
}

void Player::Init(std::string path, GraphicsManager &graphicsManager, PhysicsManager &physicsManager) {
    auto &texture = graphicsManager.loadTexture(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(960.f, 540.f);

    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(sprite.getPosition().x / 100, sprite.getPosition().y / 100); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    body = physicsManager.createBody(myBodyDef);

    boxShape.SetAsBox(((texture.getSize().x / 100) / 2), (texture.getSize().x / 100) / 2);
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1;
    body->CreateFixture(&fixtureDef);
}

void Player::Render(sf::RenderWindow &renderWindow) {
    renderWindow.draw(sprite);
}

void Player::Update() {
    sprite.setPosition(body->GetPosition().x * 100, body->GetPosition().y * 100);
    std::cout << body->GetPosition().x, body->GetPosition().y;
}



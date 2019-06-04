#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u spriteSheetDimensions, float frameRate, float speed) :
    animation(texture, spriteSheetDimensions, frameRate, "player") {
    this->speed = speed;
    still = true;
    facingRight = true;

    body.setTexture(*texture);
    body.setScale(4.0f, 4.0f);
    body.setPosition(280.0f, 490.0f);
}

Player::~Player()
{
    //dtor
}

void Player::Update(float deltaTime) {
    velocity.x *= 0.9985f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump) {
        canJump = false;
        velocity.y = -750.0f;
    }

    velocity.y += 2000*deltaTime;

    if(velocity.x > -20.0f && velocity.x < 20.0f) {
        still = true;
    } else {
        still = false;
    }
    if(velocity.x > 0)
        facingRight = true;
    else
        facingRight = false;

    if(canJump == false)
        animation.PlayerJumpUpdate(velocity, facingRight);
    else
        animation.Update(still, deltaTime, facingRight, 0);
    body.setTextureRect(animation.rectangleCut);
    body.setOrigin(this->GetHalfSize());
    body.move(velocity*deltaTime);
}

void Player::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Player::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

void Player::IsColliding(sf::Vector2f& direction, std::string object) {
    if(direction.x > 0.0f || direction.x < 0.0f)
        if(object != "crate")
            velocity.x = 0.0f;
    if(direction.y > 0.0f)
        velocity.y = 0.0f;
    if(direction.y < 0.0f){
        canJump = true;
        velocity.y = 0.0f;
    }
}

void Player::SetRandColor() {
    body.setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}

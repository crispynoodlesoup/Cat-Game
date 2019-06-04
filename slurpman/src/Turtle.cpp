#include "Turtle.h"

Turtle::Turtle(sf::Texture* texture, sf::Vector2f position, sf::Vector2u frameNum, float frameRate) :
    animation(texture, frameNum, frameRate, "turtle") {
    body.setTexture(*texture);

    body.setScale(4.0f, 4.0f);
    body.setPosition(position);
}

Turtle::~Turtle(){
}

void Turtle::Update(float deltaTime) {
    animation.Update(false, deltaTime, true, 1);
    body.setTextureRect(animation.rectangleCut);
    body.setOrigin(this->GetHalfSize());
}

void Turtle::SetPosition(sf::Vector2f position) {
    body.setPosition(position);
}

void Turtle::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Turtle::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

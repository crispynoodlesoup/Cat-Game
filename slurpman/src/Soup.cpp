#include "Soup.h"

Soup::Soup(sf::Texture* texture, sf::Vector2f position, sf::Vector2u frameNum, float frameRate) :
    animation(texture, frameNum, frameRate, "soup") {
    body.setTexture(*texture);

    body.setScale(4.0f, 4.0f);
    body.setPosition(position);
}

Soup::~Soup()
{
    //dtor
}

void Soup::Update(float deltaTime) {
    animation.Update(false, deltaTime, true, 2);
    body.setTextureRect(animation.rectangleCut);
    body.setOrigin(this->GetHalfSize());
}

void Soup::SetPosition(sf::Vector2f position) {
    body.setPosition(position);
}

void Soup::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Soup::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

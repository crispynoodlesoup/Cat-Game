#include "Cloud.h"

Cloud::Cloud(sf::Texture* texture, sf::Vector2f position) {
    body.setTexture(*texture);

    body.setTextureRect(sf::IntRect(0, 72, 64, 8));
    body.setScale(4.0f, 4.0f);
    body.setOrigin(this->GetHalfSize());
    body.setPosition(position);
}

Cloud::~Cloud()
{
    //dtor
}

void Cloud::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Cloud::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

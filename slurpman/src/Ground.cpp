#include "Ground.h"

Ground::Ground(sf::Texture* texture) {
    body.setTexture(*texture);

    body.setScale(2.0f, 2.0f);
    body.setPosition(0.0f, 688.0f);
    body.setOrigin(this->GetHalfSize());
}

Ground::~Ground()
{
    //dtor
}

void Ground::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Ground::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

#include "Boundaries.h"

Boundaries::Boundaries(sf::Texture* texture, sf::Vector2f position) {
    body.setTexture(*texture);
    body.setPosition(position);
    body.setOrigin(this->GetHalfSize());
}

Boundaries::~Boundaries()
{
    //dtor
}

void Boundaries::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Boundaries::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

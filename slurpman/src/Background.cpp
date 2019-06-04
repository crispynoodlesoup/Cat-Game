#include "Background.h"

Background::Background(sf::Texture *texture, float scaleFactor, sf::IntRect rectangleCut) {
    texture->setRepeated(true);

    background.setTexture(*texture);
    background.setColor(sf::Color(255, 255, 255, 190));
    background.setScale(scaleFactor, scaleFactor);
    background.setTextureRect(rectangleCut);
}

Background::~Background()
{
    //dtor
}

void Background::Draw(sf::RenderWindow *window) {
    window->draw(background);
}

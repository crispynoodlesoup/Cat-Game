#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background
{
    public:
        Background(sf::Texture *texture, float scaleFactor, sf::IntRect rectangleCut);
        virtual ~Background();

        void Draw(sf::RenderWindow *window);

    private:
        sf::Sprite background;
};

#endif // BACKGROUND_H

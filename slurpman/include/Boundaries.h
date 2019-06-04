#ifndef BOUNDARIES_H
#define BOUNDARIES_H

#include <SFML/Graphics.hpp>
#include "CollisionDetection.h"

class Boundaries
{
    public:
        Boundaries(sf::Texture* texture, sf::Vector2f position);
        virtual ~Boundaries();

        void Draw(sf::RenderWindow *window);
        CollisionDetection GetBody() {return CollisionDetection(body);}

        sf::Vector2f GetHalfSize();

    private:
        sf::Sprite body;
};

#endif // BOUNDARIES_H

#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>

#include "CollisionDetection.h"

class Ground
{
    public:
        Ground(sf::Texture* texture);
        virtual ~Ground();

        void Draw(sf::RenderWindow *window);

        CollisionDetection GetBody() {return CollisionDetection(body);}
        sf::Vector2f GetHalfSize();

    private:
        sf::Sprite body;
};

#endif // GROUND_H

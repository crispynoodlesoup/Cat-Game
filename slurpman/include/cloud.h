#ifndef CLOUD_H
#define CLOUD_H

#include <SFML/Graphics.hpp>
#include "CollisionDetection.h"

class Cloud
{
    public:
        Cloud(sf::Texture* texture, sf::Vector2f position);
        virtual ~Cloud();

        void Draw(sf::RenderWindow *window);
        CollisionDetection GetBody() {return CollisionDetection(body);}

        sf::Vector2f GetHalfSize();

    private:
        sf::Sprite body;
};

#endif // CLOUD_H

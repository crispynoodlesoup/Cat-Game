#ifndef CRATE_H
#define CRATE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "CollisionDetection.h"

class Crate
{
    public:
        Crate(sf::Texture* texture, sf::Vector2f position, float scale);
        virtual ~Crate();

        void Draw(sf::RenderWindow *window);
        void IsColliding(sf::Vector2f& direction);
        void Update(float deltaTime);

        CollisionDetection GetBody() {return CollisionDetection(body);}
        sf::Vector2f GetHalfSize();

    private:
        sf::Sprite body;
        sf::Vector2f velocity;
        float scale;
};

#endif // CRATE_H

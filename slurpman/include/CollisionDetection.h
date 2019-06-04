#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include <SFML/Graphics.hpp>

class CollisionDetection
{
    public:
        CollisionDetection(sf::Sprite& body);
        virtual ~CollisionDetection();

        void Move(float dx, float dy) {return body->move(dx, dy);}
        bool CheckCollided(CollisionDetection other, sf::Vector2f& direction, float pushFactor);

        sf::Vector2f GetPosition() {return body->getPosition();}
        sf::Vector2f GetHalfSize();

    private:
        sf::Sprite *body;
};

#endif // COLLISIONDETECTION_H

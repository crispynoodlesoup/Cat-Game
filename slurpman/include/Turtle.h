#ifndef TURTLE_H
#define TURTLE_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "CollisionDetection.h"

class Turtle
{
    public:
        Turtle(sf::Texture* texture, sf::Vector2f position, sf::Vector2u frameNum, float frameRate);
        virtual ~Turtle();

        void Draw(sf::RenderWindow *window);
        CollisionDetection GetBody() {return CollisionDetection(body);}

        sf::Vector2f GetHalfSize();
        void Update(float deltaTime);
        void SetPosition(sf::Vector2f position);

    private:
        sf::Sprite body;
        Animation animation;
};

#endif // TURTLE_H

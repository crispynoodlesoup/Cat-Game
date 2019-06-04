#ifndef SOUP_H
#define SOUP_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "CollisionDetection.h"

class Soup
{
    public:
        Soup(sf::Texture* texture, sf::Vector2f position, sf::Vector2u frameNum, float frameRate);
        virtual ~Soup();

        void Draw(sf::RenderWindow *window);
        CollisionDetection GetBody() {return CollisionDetection(body);}

        sf::Vector2f GetHalfSize();
        void Update(float deltaTime);
        void SetPosition(sf::Vector2f position);

    private:
        sf::Sprite body;
        Animation animation;
};

#endif // SOUP_H

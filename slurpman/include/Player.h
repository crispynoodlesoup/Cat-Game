#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include "Animation.h"
#include "CollisionDetection.h"

class Player
{
    public:
        Player(sf::Texture* texture, sf::Vector2u spriteSheetDimensions, float frameRate, float speed);
        virtual ~Player();

        void Update(float deltaTime);
        void Draw(sf::RenderWindow *window);
        void IsColliding(sf::Vector2f& direction, std::string object);
        void SetRandColor();

        CollisionDetection GetBody() {return CollisionDetection(body);}

        sf::Vector2f GetHalfSize();

    private:
        sf::Sprite body;
        Animation animation;
        bool still;
        float speed;
        bool facingRight;
        sf::Vector2f position;
        sf::Vector2f velocity;
        bool canJump;
};

#endif // PLAYER_H

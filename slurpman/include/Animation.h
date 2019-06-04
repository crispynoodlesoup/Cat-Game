#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>

class Animation {
    public:
        Animation(sf::Texture* texture, sf::Vector2u spriteSheetDimensions, float frameRate, std::string object);
        virtual ~Animation();

        void Update(bool still, float deltaTime, bool facingRight, float currentFrameY);
        void PlayerJumpUpdate(sf::Vector2f velocity, bool facingRight);

        sf::IntRect rectangleCut;

    private:
        sf::Vector2u currentFrame;
        sf::Vector2u spriteSheetDimensions;

        float totalTime;
        float frameRate;
        std::string object;
};

#endif // ANIMATION_H

#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u spriteSheetDimensions, float frameRate, std::string object) {
    this->spriteSheetDimensions = spriteSheetDimensions;
    this->frameRate = frameRate;
    this->object = object;

    totalTime = 0.0f;
    currentFrame.x = 0;
    rectangleCut.width = texture->getSize().x/float(spriteSheetDimensions.x);
    rectangleCut.height = texture->getSize().y/float(spriteSheetDimensions.y);
    if(object == "player")
        rectangleCut.height = 10.0f;
}

Animation::~Animation() {
    //dtor
}

void Animation::Update(bool still, float deltaTime, bool facingRight, float currentFrameY) {
    rectangleCut.height = 16;

    totalTime += deltaTime;

    if(totalTime >= frameRate) {
        totalTime -= frameRate;
        currentFrame.x++;

        if(currentFrame.x >= spriteSheetDimensions.x){
            currentFrame.x = 0;
        }
    }

    if(still) {
        currentFrame.x = 0;
    }

    if(facingRight) {
        rectangleCut.left = currentFrame.x*rectangleCut.width;
        rectangleCut.width = abs(rectangleCut.width);
    } else {
        rectangleCut.left = (currentFrame.x + 1)*abs(rectangleCut.width);
        rectangleCut.width = -abs(rectangleCut.width);
    }

    rectangleCut.top = currentFrameY*rectangleCut.height;
    if(object == "player" || object == "soup") {
        rectangleCut.top += 6;
        rectangleCut.height = 10;
    } else if(object == "turtle") {
        rectangleCut.top += 4;
        rectangleCut.height = 12;
    }
}

void Animation::PlayerJumpUpdate(sf::Vector2f velocity, bool facingRight) {
    rectangleCut.top = 48;

    if(velocity.y < -350.0f){
        currentFrame.x = 0;
        rectangleCut.height = 16;
    } else if(velocity.y < 0.0f && velocity.y >= -350.0f) {
        currentFrame.x = 1;
        rectangleCut.top = 49;
        rectangleCut.height = 14;
    } else if(velocity.y < 350.0f && velocity.y >= 0.0f) {
        currentFrame.x = 2;
        rectangleCut.top = 51;
        rectangleCut.height = 11;
    } else if(velocity.y >= 350.0f) {
        currentFrame.x = 3;
        rectangleCut.top = 52;
        rectangleCut.height = 12;
    }

    if(facingRight) {
        rectangleCut.left = currentFrame.x*rectangleCut.width;
        rectangleCut.width = abs(rectangleCut.width);
    } else {
        rectangleCut.left = (currentFrame.x + 1)*abs(rectangleCut.width);
        rectangleCut.width = -abs(rectangleCut.width);
    }
}

#include "CollisionDetection.h"

CollisionDetection::CollisionDetection(sf::Sprite& body) :
    body(&body)
{

}

CollisionDetection::~CollisionDetection()
{
    //dtor
}

bool CollisionDetection::CheckCollided(CollisionDetection object, sf::Vector2f& direction, float pushFactor) {
    sf::Vector2f objectPosition = object.GetPosition();
    sf::Vector2f objectHalfsize = object.GetHalfSize();
    sf::Vector2f Position = GetPosition();
    sf::Vector2f Halfsize = GetHalfSize();

    float deltaX = objectPosition.x - Position.x;
    float deltaY = objectPosition.y - Position.y;
    float intersectionX = fabs(deltaX) - (objectHalfsize.x + Halfsize.x);
    float intersectionY = fabs(deltaY) - (objectHalfsize.y + Halfsize.y);

    if(intersectionX < 0.0f && intersectionY < 0.0f) {
        if(intersectionX > intersectionY) {
            if(deltaX > 0.0f) {
                Move(intersectionX*(1.0f - pushFactor), 0.0f);
                object.Move(-intersectionX*pushFactor, 0.0f);

                direction.x = 1.0f;
                direction.y = 0.0f;
            } else {
                Move(-intersectionX*(1.0f - pushFactor), 0.0f);
                object.Move(intersectionX*pushFactor, 0.0f);

                direction.x = -1.0f;
                direction.y = 0.0f;
            }
        } else {
            if(deltaY > 0.0f) {
                Move(0.0f, intersectionY*(1.0f - pushFactor));
                object.Move(0.0f, -intersectionY*pushFactor);

                direction.x = 0.0f;
                direction.y = 1.0f;
            } else {
                Move(0.0f, -intersectionY*(1.0f - pushFactor));
                object.Move(0.0f, intersectionY*pushFactor);

                direction.x = 0.0f;
                direction.y = -1.0f;
            }
        }

        return true;
    }
    return false;
}

sf::Vector2f CollisionDetection::GetHalfSize() {
    sf::FloatRect globalBounds = body->getGlobalBounds();
    sf::Vector2f halfSize(globalBounds.width/2.0f, globalBounds.height/2.0f);
    return halfSize;
}

#include "Crate.h"

Crate::Crate(sf::Texture* texture, sf::Vector2f position, float scale) {
    this->scale = scale;
    body.setTexture(*texture);

    body.setScale(scale, scale);
    body.setOrigin(this->GetHalfSize());
    body.setPosition(position);
}

Crate::~Crate()
{
    //dtor
}

void Crate::Update(float deltaTime) {
    velocity.x *= 0.9985f;
    velocity.y += 600.0f*deltaTime*scale;
    body.move(velocity*deltaTime);
}

void Crate::Draw(sf::RenderWindow *window) {
    window->draw(body);
}

sf::Vector2f Crate::GetHalfSize() {
    sf::FloatRect localBounds = body.getLocalBounds();
    sf::Vector2f Size(localBounds.width/2.0f, localBounds.height/2.0f);
    return Size;
}

void Crate::IsColliding(sf::Vector2f& direction) {
    if(direction.x > 0.0f || direction.x < 0.0f)
            velocity.x = 0.0f;
    if(direction.y > 0.0f || direction.y < 0.0f)
            velocity.y = 0.0f;
}

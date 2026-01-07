#include "Platform.hpp"

engine::Platform::Platform(int id, sf::Vector2f size, sf::Vector2f position)
    : engine::GameObject(id)
{
    boundingBox = sf::RectangleShape(size);
    boundingBox.setPosition(position);
}

void engine::Platform::draw(sf::RenderTarget& target) { target.draw(boundingBox); }
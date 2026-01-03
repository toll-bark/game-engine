#include "Platform.hpp"

engine::Platform::Platform(sf::Vector2f size, sf::Vector2f position)
{
    boundingBox = sf::RectangleShape(size);
    boundingBox.setPosition(position);
}
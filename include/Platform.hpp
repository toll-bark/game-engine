#ifndef engine_Platform
#define engine_Platform

#include <SFML/Graphics.hpp>

namespace engine
{
    class Platform
    {
    public:
        sf::RectangleShape boundingBox;

        Platform(sf::Vector2f size, sf::Vector2f position);
    };
}

#endif
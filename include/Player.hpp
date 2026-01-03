#ifndef engine_Player
#define engine_Player

#include <SFML/Graphics.hpp>

namespace engine
{
    class Player
    {
    public:
        sf::RectangleShape boundingBox;
        sf::Vector2f velocity;

        Player(sf::Vector2f position);
        void update();
    };
}

#endif
#ifndef engine_Player
#define engine_Player

#include "IDrawable.hpp"

namespace engine
{
    class Player : public IDrawable
    {
    public:
        sf::RectangleShape boundingBox;
        sf::Vector2f velocity;

        Player(sf::Vector2f position);
        virtual void draw(sf::RenderTarget& target) override;
        void update();
    };
}

#endif
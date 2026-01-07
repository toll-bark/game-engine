#ifndef engine_Player
#define engine_Player

#include "GameObject.hpp"
#include "IDrawable.hpp"

namespace engine
{
    class Player : public IDrawable, public GameObject
    {
    public:
        sf::RectangleShape boundingBox;
        sf::Vector2f velocity;

        Player(int, sf::Vector2f position);
        virtual void draw(sf::RenderTarget& target) override;
        void update();
    };
}

#endif
#ifndef engine_Player
#define engine_Player

#include <engine/GameObject/Behavior/IDrawable.hpp>
#include <engine/GameObject/Behavior/IUpdateable.hpp>
#include <engine/GameObject/GameObject.hpp>

namespace engine
{
    class Player : public IDrawable, public IUpdateable, public GameObject
    {
    public:
        sf::RectangleShape boundingBox;
        sf::Vector2f velocity;

        Player(int, sf::Vector2f position);
        virtual void draw(sf::RenderTarget& target) override;
        virtual void update(void) override;
    };
}

#endif
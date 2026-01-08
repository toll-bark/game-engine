#ifndef engine_Platform
#define engine_Platform

#include <engine/GameObject/Behavior/IDrawable.hpp>
#include <engine/GameObject/GameObject.hpp>

namespace engine
{
    class Platform final : public IDrawable, public GameObject
    {
    public:
        sf::RectangleShape boundingBox;

        Platform(int, sf::Vector2f size, sf::Vector2f position);
        virtual void draw(sf::RenderTarget& target) override;
    };
}

#endif
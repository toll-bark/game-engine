#ifndef engine_Platform
#define engine_Platform

#include "GameObject.hpp"
#include "IDrawable.hpp"

namespace engine
{
    class Platform : public IDrawable, public GameObject
    {
    public:
        sf::RectangleShape boundingBox;

        Platform(int, sf::Vector2f size, sf::Vector2f position);
        virtual void draw(sf::RenderTarget& target) override;
    };
}

#endif
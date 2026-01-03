#ifndef engine_Platform
#define engine_Platform

#include "IDrawable.hpp"

namespace engine
{
    class Platform : public IDrawable
    {
    public:
        sf::RectangleShape boundingBox;

        Platform(sf::Vector2f size, sf::Vector2f position);
        virtual void draw(sf::RenderTarget& target) override;
    };
}

#endif
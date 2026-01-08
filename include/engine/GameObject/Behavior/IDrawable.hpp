#ifndef engine_IDrawable
#define engine_IDrawable

#include <SFML/Graphics.hpp>

namespace engine
{
    class IDrawable
    {
    public:
        virtual void draw(sf::RenderTarget& target) = 0;
    };
}

#endif
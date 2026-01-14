#ifndef engine_DefaultPlatformFactory
#define engine_DefualtPlatformFactory

#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlatformFactory.hpp>

namespace engine
{
    class DefaultPlatformFactory final : public AbstractPlatformFactory
    {
    public:
        DefaultPlatformFactory(AbstractGameObjectManager& gom, BehaviorFactoryTemplate<IDrawable>&  drawableFactory)
            : AbstractPlatformFactory(gom, drawableFactory) {}
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) override;
        virtual void remove(int id) override;
        ~DefaultPlatformFactory();
    };
}

#endif
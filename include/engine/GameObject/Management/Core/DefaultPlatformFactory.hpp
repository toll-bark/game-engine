#ifndef engine_DefaultPlatformFactory
#define engine_DefualtPlatformFactory

#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlatformFactory.hpp>

namespace engine
{
    class DefaultPlatformFactory : public AbstractPlatformFactory
    {
    private:
        std::unordered_map<int, Platform*> trackedObjects = {};
        AbstractGameObjectManager& gom;
        BehaviorFactoryTemplate<IDrawable>& drawableFactory;
    public:
        DefaultPlatformFactory(AbstractGameObjectManager& gom, BehaviorFactoryTemplate<IDrawable>&  drawableFactory)
            : AbstractPlatformFactory(gom), gom(gom), drawableFactory(drawableFactory) {}
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) override;
        ~DefaultPlatformFactory();
    };
}

#endif
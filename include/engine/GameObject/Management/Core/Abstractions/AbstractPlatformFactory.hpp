#ifndef engine_AbstractPlatformFactory
#define engine_AbstractPlatformFactory

#include <unordered_map>

#include <engine/GameObject/Derived/Platform.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/DerivedFactoryTemplate.hpp>

namespace engine
{
    class AbstractPlatformFactory : public DerivedFactoryTemplate<Platform>
    {
    protected:
        BehaviorFactoryTemplate<IDrawable>& drawableFactory;
    public:
        AbstractPlatformFactory(AbstractGameObjectManager& objectManager, BehaviorFactoryTemplate<IDrawable>& drawableFactory) 
            : DerivedFactoryTemplate(objectManager), drawableFactory(drawableFactory) {}
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) = 0;
        virtual ~AbstractPlatformFactory() = default;
    };
}

#endif
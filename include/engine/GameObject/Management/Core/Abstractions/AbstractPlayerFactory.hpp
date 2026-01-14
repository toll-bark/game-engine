#ifndef engine_AbstractPlayerFactory
#define engine_AbstractPlayerFactory

#include <unordered_map>

#include <engine/GameObject/Derived/Player.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/DerivedFactoryTemplate.hpp>

namespace engine 
{
    class AbstractPlayerFactory : public DerivedFactoryTemplate<Player>
    {
    protected:
        BehaviorFactoryTemplate<engine::IDrawable>& drawableFactory;
        BehaviorFactoryTemplate<engine::IUpdateable>& updateableFactory;
    public:
        AbstractPlayerFactory(AbstractGameObjectManager& gom, BehaviorFactoryTemplate<engine::IDrawable>& drawableFactory, 
            BehaviorFactoryTemplate<engine::IUpdateable>& updateableFactory) 
            : DerivedFactoryTemplate(gom), drawableFactory(drawableFactory), updateableFactory(updateableFactory) {}
        virtual Player& create(sf::Vector2f position) = 0;
        virtual ~AbstractPlayerFactory() = default;
    };
}

#endif
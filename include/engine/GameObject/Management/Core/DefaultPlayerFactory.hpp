#ifndef engine_DefaultPlayerFactory
#define engine_DefaultPlayerFactory

#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlayerFactory.hpp>

namespace engine
{
    class DefaultPlayerFactory final : public AbstractPlayerFactory
    {
    public:
        DefaultPlayerFactory(AbstractGameObjectManager& gom, BehaviorFactoryTemplate<engine::IDrawable>& drawableFactory, 
            BehaviorFactoryTemplate<engine::IUpdateable>& updateableFactory)
            : AbstractPlayerFactory(gom, drawableFactory, updateableFactory) {}
        virtual Player& create(sf::Vector2f position) override;
        virtual void remove(int id) override;
        ~DefaultPlayerFactory();
    };
}

#endif
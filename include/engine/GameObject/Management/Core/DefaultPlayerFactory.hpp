#ifndef engine_DefaultPlayerFactory
#define engine_DefaultPlayerFactory

#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlayerFactory.hpp>

namespace engine
{
    class DefaultPlayerFactory final : public AbstractPlayerFactory
    {
        AbstractGameObjectManager& gom;
        BehaviorFactoryTemplate<engine::IDrawable>& drawableFactory;
        BehaviorFactoryTemplate<engine::IUpdateable>& updateableFactory;
    public:
        DefaultPlayerFactory(AbstractGameObjectManager& gom, 
            BehaviorFactoryTemplate<engine::IDrawable>& drawableFactory, 
            BehaviorFactoryTemplate<engine::IUpdateable>& updateableFactory)
            : AbstractPlayerFactory(gom), gom(gom), drawableFactory(drawableFactory), updateableFactory(updateableFactory) {}
        virtual Player& create(sf::Vector2f position) override;
        virtual void onNext(int id) override  
        {  
            if (objects.count(id) > 0) 
            { 
                delete objects[id]; 
                objects.erase(id);
            }
        }
        ~DefaultPlayerFactory();
    };
}

#endif
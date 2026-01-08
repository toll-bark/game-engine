#ifndef engine_DefaultPlatformFactory
#define engine_DefualtPlatformFactory

#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlatformFactory.hpp>

namespace engine
{
    class DefaultPlatformFactory : public AbstractPlatformFactory
    {
    private:
        AbstractGameObjectManager& gom;
        BehaviorFactoryTemplate<IDrawable>& drawableFactory;
    public:
        DefaultPlatformFactory(AbstractGameObjectManager& gom, BehaviorFactoryTemplate<IDrawable>&  drawableFactory)
            : AbstractPlatformFactory(gom), gom(gom), drawableFactory(drawableFactory) {}
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) override;
        virtual void onNext(int id) override  
        { 
            if (objects.count(id) > 0) 
            { 
                delete objects[id]; 
                objects.erase(id);
            }
        }
        ~DefaultPlatformFactory();
    };
}

#endif
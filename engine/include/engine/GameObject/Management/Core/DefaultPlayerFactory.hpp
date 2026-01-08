#ifndef engine_DefaultPlayerFactory
#define engine_DefaultPlayerFactory

#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractDrawableFactory.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlayerFactory.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractUpdateableFactory.hpp>

namespace engine
{
    class DefaultPlayerFactory 
        : public AbstractPlayerFactory
    {
        AbstractGameObjectManager& gom;
        AbstractDrawableFactory& drawableFactory;
        AbstractUpdateableFactory& updateableFactory;
    public:
        DefaultPlayerFactory(AbstractGameObjectManager& gom, AbstractDrawableFactory& drawableFactory, AbstractUpdateableFactory& updateableFactory)
            : AbstractPlayerFactory(gom), gom(gom), updateableFactory(updateableFactory), drawableFactory(drawableFactory) {}
        virtual Player& create(sf::Vector2f position) override;
        virtual std::vector<Player*> getAll(void) override;
        ~DefaultPlayerFactory();
    };
}

#endif
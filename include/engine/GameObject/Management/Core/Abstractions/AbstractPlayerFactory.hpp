#ifndef engine_AbstractPlayerFactory
#define engine_AbstractPlayerFactory

#include <unordered_map>

#include <engine/GameObject/Derived/Player.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/GameObjectFactoryTemplate.hpp>

namespace engine 
{
    class AbstractPlayerFactory : public GameObjectFactoryTemplate<Player>
    {
    public:
        AbstractPlayerFactory(AbstractGameObjectManager& gom) : GameObjectFactoryTemplate(gom) {}
        virtual Player& create(sf::Vector2f position) = 0;
        virtual ~AbstractPlayerFactory() = default;
    };
}

#endif
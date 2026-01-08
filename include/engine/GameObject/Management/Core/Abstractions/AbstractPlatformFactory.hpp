#ifndef engine_AbstractPlatformFactory
#define engine_AbstractPlatformFactory

#include <unordered_map>

#include <engine/GameObject/Derived/Platform.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/GameObjectFactoryTemplate.hpp>

namespace engine
{
    class AbstractPlatformFactory : public GameObjectFactoryTemplate<Platform>
    {
    public:
        AbstractPlatformFactory(AbstractGameObjectManager& objectManager) : GameObjectFactoryTemplate(objectManager) {}
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) = 0;
    };
}

#endif
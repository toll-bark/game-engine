#ifndef engine_AbstractPlatformFactory
#define engine_AbstractPlatformFactory

#include <unordered_map>

#include <engine/GameObject/Derived/Platform.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectFactory.hpp>

namespace engine
{
    class AbstractPlatformFactory : public AbstractGameObjectFactory<Platform>
    {
    protected:
        std::unordered_map<int, Platform> objects = {};
    public:
        AbstractPlatformFactory(AbstractGameObjectManager& objectManager) : AbstractGameObjectFactory(objectManager) {}
        virtual void onNext(int id) override { objects.erase(id); }
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) = 0;
    };
}

#endif
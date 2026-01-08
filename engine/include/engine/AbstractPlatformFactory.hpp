#ifndef engine_AbstractPlatformFactory
#define engine_AbstractPlatformFactory

#include <unordered_map>

#include <engine/AbstractGameObjectManager.hpp>
#include <engine/IGameObjectDeleteObserver.hpp>
#include <engine/IGameObjectFactory.hpp>
#include <engine/Platform.hpp>

namespace engine
{
    class AbstractPlatformFactory : public IGameObjectFactory<Platform>, public IGameObjectDeleteObserver
    {
    protected:
        std::unordered_map<int, Platform> objects = {};
    public:
        AbstractPlatformFactory(AbstractGameObjectManager& objectManager) { objectManager.enroll(*this); }
        virtual void onNext(int id) override { objects.erase(id); }
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) = 0;
    };
}

#endif
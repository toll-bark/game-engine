#ifndef engine_AbstractPlatformFactory
#define engine_AbstractPlatformFactory

#include <unordered_map>

#include "AbstractGameObjectManager.hpp"
#include "IGameObjectDeleteObserver.hpp"
#include "IGameObjectFactory.hpp"
#include "Platform.hpp"

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
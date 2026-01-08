#ifndef engine_AbstractPlayerFactory
#define engine_AbstractPlayerFactory

#include <unordered_map>

#include <engine/AbstractGameObjectManager.hpp>
#include <engine/IGameObjectFactory.hpp>
#include <engine/IGameObjectDeleteObserver.hpp>
#include <engine/Player.hpp>

namespace engine 
{
    class AbstractPlayerFactory
        : public IGameObjectFactory<Player>,
            public IGameObjectDeleteObserver
    {
    protected:
        std::unordered_map<int, Player*> trackedObjects = {};
    public:
        AbstractPlayerFactory(AbstractGameObjectManager& gom) { gom.enroll(*this); }
        virtual Player& create(sf::Vector2f position) = 0;
        virtual void onNext(int id) override { if (trackedObjects.count(id) > 0) delete trackedObjects[id]; }
    };
}

#endif
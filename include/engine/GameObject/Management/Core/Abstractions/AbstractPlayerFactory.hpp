#ifndef engine_AbstractPlayerFactory
#define engine_AbstractPlayerFactory

#include <unordered_map>

#include <engine/GameObject/Derived/Player.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectFactory.hpp>

namespace engine 
{
    class AbstractPlayerFactory
        : public AbstractGameObjectFactory<Player>
    {
    protected:
        std::unordered_map<int, Player*> trackedObjects = {};
    public:
        AbstractPlayerFactory(AbstractGameObjectManager& gom) : AbstractGameObjectFactory(gom) {}
        virtual Player& create(sf::Vector2f position) = 0;
        virtual void onNext(int id) override { if (trackedObjects.count(id) > 0) delete trackedObjects[id]; }
    };
}

#endif
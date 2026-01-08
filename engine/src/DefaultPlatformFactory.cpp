#include <engine/DefaultPlatformFactory.hpp>

engine::Platform& engine::DefaultPlatformFactory::create(sf::Vector2f size, sf::Vector2f position)
{
    Platform* res = new Platform(gom.nextId(), size, position);
    gom.insert(res->id);
    drawableFactory.insert(res->id, *res);
    trackedObjects[res->id] = res;
    return *res;
}

std::vector<engine::Platform*> engine::DefaultPlatformFactory::getAll(void)
{
    std::vector<engine::Platform*> res = {};
    for (std::pair<int, Platform*> kvp : trackedObjects) { res.push_back(kvp.second); }
    return res;
}

void engine::DefaultPlatformFactory::onNext(int id) { if (trackedObjects.count(id) > 0) delete trackedObjects[id]; }

engine::DefaultPlatformFactory::~DefaultPlatformFactory() { for (std::pair<int, engine::Platform*> kvp : trackedObjects) { delete kvp.second; } }
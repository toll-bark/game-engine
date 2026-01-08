#include <engine/GameObject/Management/Core/DefaultPlatformFactory.hpp>

engine::Platform& engine::DefaultPlatformFactory::create(sf::Vector2f size, sf::Vector2f position)
{
    Platform* res = new Platform(gom.nextId(), size, position);
    gom.insert(res->id);
    drawableFactory.insert(res->id, *res);
    trackedObjects[res->id] = res;
    return *res;
}

engine::DefaultPlatformFactory::~DefaultPlatformFactory() { for (std::pair<int, engine::Platform*> kvp : trackedObjects) { delete kvp.second; } }
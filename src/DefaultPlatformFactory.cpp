#include <engine/GameObject/Management/Core/DefaultPlatformFactory.hpp>

engine::Platform& engine::DefaultPlatformFactory::create(sf::Vector2f size, sf::Vector2f position)
{
    Platform* res = new Platform(gom.nextId(), size, position);
    gom.insert(res->id);
    drawableFactory.insert(res->id, *res);
    objects[res->id] = res;
    return *res;
}

void engine::DefaultPlatformFactory::remove(int id) { delete objects[id]; }

engine::DefaultPlatformFactory::~DefaultPlatformFactory() { for (std::pair<int, engine::Platform*> kvp : objects) { remove(kvp.first); } }
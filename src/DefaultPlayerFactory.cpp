#include <engine/GameObject/Management/Core/DefaultPlayerFactory.hpp>

engine::Player& engine::DefaultPlayerFactory::create(sf::Vector2f position)
{
    engine::Player* res = new engine::Player(gom.nextId(), position);
    gom.insert(res->id);
    updateableFactory.insert(res->id, *res);
    drawableFactory.insert(res->id, *res);
    objects[res->id] = res;
    return *res;
}

engine::DefaultPlayerFactory::~DefaultPlayerFactory() { for (std::pair<int, engine::Player*> kvp : objects) { delete kvp.second; } }
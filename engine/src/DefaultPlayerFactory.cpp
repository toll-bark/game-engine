#include <engine/DefaultPlayerFactory.hpp>

engine::Player& engine::DefaultPlayerFactory::create(sf::Vector2f position)
{
    engine::Player* res = new engine::Player(gom.nextId(), position);
    gom.insert(res->id);
    updateableFactory.insert(res->id, *res);
    drawableFactory.insert(res->id, *res);
    trackedObjects[res->id] = res;
    return *res;
}

std::vector<engine::Player*> engine::DefaultPlayerFactory::getAll(void)
{
    std::vector<engine::Player*> res = {};
    for (std::pair<int, engine::Player*> kvp : trackedObjects) { res.push_back(kvp.second); }
    return res;
}

engine::DefaultPlayerFactory::~DefaultPlayerFactory() { for (std::pair<int, engine::Player*> kvp : trackedObjects) { delete kvp.second; } }
#include <engine/DefaultUpdateableFactory.hpp>

std::vector<engine::IUpdateable*> engine::DefaultUpdateableFactory::getAll(void) 
{
	std::vector<engine::IUpdateable*> res = {};
	for (std::pair<int, engine::IUpdateable*> kvp : objects) { res.push_back(kvp.second); }
	return res;
}

void engine::DefaultUpdateableFactory::onNext(int id) { if (objects.count(id) > 0) objects.erase(id); }
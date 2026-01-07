#include "DefaultDrawableFactory.hpp"

std::vector<engine::IDrawable*> engine::DefaultDrawableFactory::getAll(void) {
	std::vector<engine::IDrawable*> res = {};
	for (std::pair<int, IDrawable*> kvp : objects) { res.push_back(kvp.second); }
	return res;
}

void engine::DefaultDrawableFactory::onNext(int id) { if (objects.count(id) > 0) objects.erase(id); }
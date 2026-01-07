#include "DefaultGameObjectManager.hpp"

#include <stdexcept>
#include <sstream>

void engine::DefaultGameObjectManager::deleteGameObject(int id)
{
	trackedObjects.erase(id);
	for (auto& observer : observers) { observer->onNext(id); }
}

void engine::DefaultGameObjectManager::enroll(IGameObjectDeleteObserver& observer) { observers.push_back(&observer); }

void engine::DefaultGameObjectManager::insert(int id)
{
	if (trackedObjects.count(id) > 0)
	{
		std::stringstream ss;
		ss << "ID "
			<< id
			<< "is already in use";
		throw new std::invalid_argument(ss.str());
	}

	trackedObjects.insert(id);
	if (id > highestId) highestId = id;
}

int engine::DefaultGameObjectManager::nextId(void) { return highestId + 1; }
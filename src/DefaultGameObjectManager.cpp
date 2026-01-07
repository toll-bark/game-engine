#include "DefaultGameObjectManager.hpp"

void engine::DefaultGameObjectManager::deleteGameObject(int id)
{
	trackedGameObjects.erase(id);
	for (auto& observer : observers) { observer->onNext(id); }
}

void engine::DefaultGameObjectManager::enroll(IGameObjectDeleteObserver& observer) { observers.push_back(&observer); }
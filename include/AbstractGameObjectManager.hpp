#ifndef engine_AbstractGameObjectManager
#define engine_AbstractGameObjectManager

#include <unordered_set>

#include "IGameObjectDeleteObserver.hpp"

namespace engine
{
	class AbstractGameObjectManager
	{
	public:
		std::unordered_set<int> trackedGameObjects = {};
		virtual void deleteGameObject(int) = 0;
		virtual void enroll(IGameObjectDeleteObserver&) = 0;
	};
}

#endif
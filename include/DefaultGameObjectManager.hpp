#ifndef engine_DefaultGameObjectManager
#define engine_DefaultGameObjectManager

#include <vector>
#include <unordered_set>

#include "AbstractGameObjectManager.hpp"

namespace engine
{
	class DefaultGameObjectManager : public AbstractGameObjectManager
	{
		int highestId = -1;
		std::unordered_set<int> trackedObjects = {};
		std::vector<IGameObjectDeleteObserver*> observers = {};
	public:
		virtual void deleteGameObject(int) override;
		virtual void enroll(IGameObjectDeleteObserver&) override;
		virtual void insert(int) override;
		virtual int nextId(void) override;
	};
}

#endif
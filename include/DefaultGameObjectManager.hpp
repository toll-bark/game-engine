#ifndef engine_DefaultGameObjectManager
#define engine_DefaultGameObjectManager

#include <vector>

#include "AbstractGameObjectManager.hpp"

namespace engine
{
	class DefaultGameObjectManager : public AbstractGameObjectManager
	{
		std::vector<IGameObjectDeleteObserver*> observers = {};
	public:
		virtual void deleteGameObject(int) override;
		virtual void enroll(IGameObjectDeleteObserver&) override;
	};
}

#endif
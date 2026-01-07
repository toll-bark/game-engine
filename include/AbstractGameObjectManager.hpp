#ifndef engine_AbstractGameObjectManager
#define engine_AbstractGameObjectManager

#include "IGameObjectDeleteObserver.hpp"

namespace engine
{
	class AbstractGameObjectManager
	{
	public:
		virtual void deleteGameObject(int) = 0;
		virtual void enroll(IGameObjectDeleteObserver&) = 0;
		virtual void insert(int) = 0;
		virtual int nextId(void) = 0;
	};
}

#endif
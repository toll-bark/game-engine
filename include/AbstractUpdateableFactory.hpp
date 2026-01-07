#ifndef engine_AbstractUpdateableFactory
#define engine_AbstractUpdateableFactory

#include "AbstractGameObjectManager.hpp"
#include "IBehaviorFactory.hpp"
#include "IGameObjectDeleteObserver.hpp"
#include "IGameObjectFactory.hpp"
#include "IUpdateable.hpp"

#include <unordered_map>

namespace engine
{
	class AbstractUpdateableFactory : public IGameObjectFactory<IUpdateable*>, public IBehaviorFactory<IUpdateable*>, public IGameObjectDeleteObserver
	{
	protected:
		std::unordered_map<int, IUpdateable*> objects = {};
	public:
		AbstractUpdateableFactory(AbstractGameObjectManager& objectManager) { objectManager.enroll(*this); }
		virtual void insert(int id, IUpdateable* object) override { objects[id] = object; }
	};
}

#endif
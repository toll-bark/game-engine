#ifndef engine_AbstractUpdateableFactory
#define engine_AbstractUpdateableFactory

#include <unordered_map>

#include <engine/AbstractGameObjectManager.hpp>
#include <engine/IBehaviorFactory.hpp>
#include <engine/IGameObjectDeleteObserver.hpp>
#include <engine/IGameObjectFactory.hpp>
#include <engine/IUpdateable.hpp>

namespace engine
{
	class AbstractUpdateableFactory : public IGameObjectFactory<IUpdateable>, public IBehaviorFactory<IUpdateable>, public IGameObjectDeleteObserver
	{
	protected:
		std::unordered_map<int, IUpdateable*> objects = {};
	public:
		AbstractUpdateableFactory(AbstractGameObjectManager& objectManager) { objectManager.enroll(*this); }
		virtual void insert(int id, IUpdateable& object) override { objects[id] = &object; }
	};
}

#endif
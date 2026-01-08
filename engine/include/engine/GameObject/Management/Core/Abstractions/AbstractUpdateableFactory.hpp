#ifndef engine_AbstractUpdateableFactory
#define engine_AbstractUpdateableFactory

#include <unordered_map>

#include <engine/GameObject/Behavior/IUpdateable.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/IBehaviorFactory.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectFactory.hpp>

namespace engine
{
	class AbstractUpdateableFactory : public AbstractGameObjectFactory<IUpdateable>, public IBehaviorFactory<IUpdateable>
	{
	protected:
		std::unordered_map<int, IUpdateable*> objects = {};
	public:
		AbstractUpdateableFactory(AbstractGameObjectManager& objectManager) : AbstractGameObjectFactory(objectManager) {}
		virtual void insert(int id, IUpdateable& object) override { objects[id] = &object; }
	};
}

#endif
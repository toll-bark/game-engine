#ifndef engine_AbstractUpdateableFactory
#define engine_AbstractUpdateableFactory

#include <unordered_map>

#include <engine/GameObject/Behavior/IUpdateable.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/IBehaviorFactory.hpp>
#include <engine/GameObject/Management/Abstractions/IGameObjectFactory.hpp>
#include <engine/GameObject/Management/Core/Abstractions/IGameObjectDeleteObserver.hpp>

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
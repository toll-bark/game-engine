#ifndef engine_AbstractUpdateableFactory
#define engine_AbstractUpdateableFactory

#include <unordered_map>

#include <engine/GameObject/Behavior/IUpdateable.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>

namespace engine
{
	class AbstractUpdateableFactory : public BehaviorFactoryTemplate<IUpdateable>
	{
	public:
		AbstractUpdateableFactory(AbstractGameObjectManager& objectManager) : BehaviorFactoryTemplate<IUpdateable>(objectManager) {}
	};
}

#endif
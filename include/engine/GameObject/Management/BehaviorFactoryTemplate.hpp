#ifndef engine_IBehaviorFactory
#define engine_IBehaviorFactory

#include <vector>

#include <engine/GameObject/Management/GameObjectFactoryTemplate.hpp>

namespace engine
{
	template <class T>
	class BehaviorFactoryTemplate : public GameObjectFactoryTemplate<T>
	{
	public:
		BehaviorFactoryTemplate<T>(AbstractGameObjectManager& gom) : GameObjectFactoryTemplate<T>(gom) {}
		void insert(int id, T& object) { this->objects[id] = &object; }
	};
}

#endif
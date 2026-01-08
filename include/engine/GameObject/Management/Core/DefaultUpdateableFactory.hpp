#ifndef engine_DefaultUpdateableFactory
#define engine_DefaultUpdateableFactory

#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>

namespace engine
{
	class DefaultUpdateableFactory final : public BehaviorFactoryTemplate<IUpdateable>
	{
	public:
		DefaultUpdateableFactory(AbstractGameObjectManager& manager) : BehaviorFactoryTemplate<IUpdateable>(manager) {}
	};
}

#endif
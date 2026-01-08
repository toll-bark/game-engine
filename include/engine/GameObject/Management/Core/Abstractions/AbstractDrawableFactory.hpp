#ifndef engine_AbstractDrawableFactory
#define engine_AbstractDrawableFactory

#include <engine/GameObject/Behavior/IDrawable.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>

namespace engine
{
	class AbstractDrawableFactory : public BehaviorFactoryTemplate<IDrawable>
	{
	public:
		AbstractDrawableFactory(AbstractGameObjectManager& objectManager) : BehaviorFactoryTemplate<IDrawable>(objectManager) {}
	};
}

#endif
#ifndef engine_DefaultDrawableFactory
#define engine_DefaultDrawableFactory

#include <engine/GameObject/Behavior/IDrawable.hpp>
#include <engine/GameObject/Management/BehaviorFactoryTemplate.hpp>

namespace engine
{
	class DefaultDrawableFactory final : public BehaviorFactoryTemplate<IDrawable>
	{
	public:
		DefaultDrawableFactory(AbstractGameObjectManager& manager) : BehaviorFactoryTemplate<IDrawable>(manager) {}
	};
}

#endif
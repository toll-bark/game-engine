#ifndef engine_DefaultDrawableFactory
#define engine_DefaultDrawableFactory

#include <engine/GameObject/Management/Core/Abstractions/AbstractDrawableFactory.hpp>

namespace engine
{
	class DefaultDrawableFactory : public AbstractDrawableFactory
	{
	public:
		DefaultDrawableFactory(AbstractGameObjectManager& manager) : AbstractDrawableFactory(manager) {}
	};
}

#endif
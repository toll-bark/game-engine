#ifndef engine_DefaultUpdateableFactory
#define engine_DefaultUpdateableFactory

#include <engine/GameObject/Management/Core/Abstractions/AbstractUpdateableFactory.hpp>

namespace engine
{
	class DefaultUpdateableFactory : public AbstractUpdateableFactory
	{
	public:
		DefaultUpdateableFactory(AbstractGameObjectManager& manager) : AbstractUpdateableFactory(manager) {}
	};
}

#endif
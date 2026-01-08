#ifndef engine_IGameObjectFactory
#define engine_IGameObjectFactory

#include <vector>

#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/IGameObjectDeleteObserver.hpp>

namespace engine
{
	template <class T>
	class AbstractGameObjectFactory : public IGameObjectDeleteObserver
	{
	public:
		AbstractGameObjectFactory(AbstractGameObjectManager& gom) { gom.enroll(*this); }
		virtual std::vector<T*> getAll(void) = 0;
	};
}

#endif
#ifndef engine_IGameObjectFactory
#define engine_IGameObjectFactory

#include <vector>

namespace engine
{
	template <class T>
	class IGameObjectFactory
	{
	public:
		virtual std::vector<T> getAll(void) = 0;
	};
}

#endif
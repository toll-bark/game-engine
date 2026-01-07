#ifndef engine_IBehaviorFactory
#define engine_IBehaviorFactory

#include <vector>

namespace engine
{
	template <class T>
	class IBehaviorFactory
	{
	public:
		virtual void insert(int, T) = 0;
	};
}

#endif
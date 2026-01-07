#ifndef engine_IUpdateable
#define engine_IUpdateable

namespace engine
{
	class IUpdateable
	{
	public:
		virtual void update(void) = 0;
	};
}

#endif
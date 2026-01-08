#ifndef engine_IGameObjectDeleteObserver
#define engine_IGameObjectDeleteObserver

namespace engine
{
	class IGameObjectDeleteObserver
	{
	public:
		virtual void onNext(int) = 0;
	};
}

#endif
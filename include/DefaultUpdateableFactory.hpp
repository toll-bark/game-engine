#ifndef engine_DefaultUpdateableFactory
#define engine_DefaultUpdateableFactory

#include "AbstractUpdateableFactory.hpp"

namespace engine
{
	class DefaultUpdateableFactory : public AbstractUpdateableFactory
	{
	public:
		virtual std::vector<IUpdateable*> getAll(void) override;
		virtual void onNext(int) override;
	};
}

#endif
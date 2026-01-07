#ifndef engine_DefaultDrawableFactory
#define engine_DefaultDrawableFactory

#include "AbstractDrawableFactory.hpp"

namespace engine
{
	class DefaultDrawableFactory : public AbstractDrawableFactory
	{
	public:
		virtual std::vector<IDrawable*> getAll(void) override;
		virtual void onNext(int) override;
	};
}

#endif
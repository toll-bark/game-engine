#ifndef engine_DefaultDrawableFactory
#define engine_DefaultDrawableFactory

#include <engine/AbstractDrawableFactory.hpp>

namespace engine
{
	class DefaultDrawableFactory : public AbstractDrawableFactory
	{
	public:
		DefaultDrawableFactory(AbstractGameObjectManager& manager) : AbstractDrawableFactory(manager) {}
		virtual std::vector<IDrawable*> getAll(void) override;
		virtual void onNext(int) override;
	};
}

#endif
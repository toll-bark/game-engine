#ifndef engine_DefaultUpdateableFactory
#define engine_DefaultUpdateableFactory

#include <engine/AbstractUpdateableFactory.hpp>

namespace engine
{
	class DefaultUpdateableFactory : public AbstractUpdateableFactory
	{
	public:
		DefaultUpdateableFactory(AbstractGameObjectManager& manager) : AbstractUpdateableFactory(manager) {}
		virtual std::vector<IUpdateable*> getAll(void) override;
		virtual void onNext(int) override;
	};
}

#endif
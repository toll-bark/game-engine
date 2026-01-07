#ifndef engine_AbstractDrawableFactory
#define engine_AbstractDrawableFactory

#include "AbstractGameObjectManager.hpp"
#include "IBehaviorFactory.hpp"
#include "IDrawable.hpp"
#include "IGameObjectFactory.hpp"
#include "IGameObjectDeleteObserver.hpp"

namespace engine
{
	class AbstractDrawableFactory : public IGameObjectFactory<IDrawable>, public IBehaviorFactory<IDrawable>, public IGameObjectDeleteObserver
	{
	protected:
		std::unordered_map<int, IDrawable*> objects = {};
	public:
		AbstractDrawableFactory(AbstractGameObjectManager& objectManager) { objectManager.enroll(*this); }
		virtual void insert(int id, IDrawable& object) override { objects[id] = &object; }
	};
}

#endif
#ifndef engine_AbstractDrawableFactory
#define engine_AbstractDrawableFactory

#include <engine/AbstractGameObjectManager.hpp>
#include <engine/IBehaviorFactory.hpp>
#include <engine/IDrawable.hpp>
#include <engine/IGameObjectFactory.hpp>
#include <engine/IGameObjectDeleteObserver.hpp>

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
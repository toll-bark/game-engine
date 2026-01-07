#ifndef engine_AbstractDrawableFactory
#define engine_AbstractDrawableFactory

#include "AbstractGameObjectManager.hpp"
#include "IDrawable.hpp"
#include "IGameObjectFactory.hpp"
#include "IGameObjectDeleteObserver.hpp"

namespace engine
{
	class AbstractDrawableFactory : public IGameObjectFactory<IDrawable*>, public IGameObjectDeleteObserver
	{
	protected:
		std::unordered_map<int, IDrawable*> objects = {};
	public:
		AbstractDrawableFactory(AbstractGameObjectManager& objectManager) { objectManager.enroll(*this); }
		void insert(int id, IDrawable* object) { objects[id] = object; }
	};
}

#endif
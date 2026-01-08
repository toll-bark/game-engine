#ifndef engine_AbstractDrawableFactory
#define engine_AbstractDrawableFactory

#include <engine/GameObject/Behavior/IDrawable.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/IBehaviorFactory.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectFactory.hpp>

namespace engine
{
	class AbstractDrawableFactory : public AbstractGameObjectFactory<IDrawable>, public IBehaviorFactory<IDrawable>
	{
	protected:
		std::unordered_map<int, IDrawable*> objects = {};
	public:
		AbstractDrawableFactory(AbstractGameObjectManager& objectManager) : AbstractGameObjectFactory<IDrawable>(objectManager) {}
		virtual void insert(int id, IDrawable& object) override { objects[id] = &object; }
	};
}

#endif
#ifndef engine_AbstractDrawableFactory
#define engine_AbstractDrawableFactory

#include <engine/GameObject/Behavior/IDrawable.hpp>
#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/IBehaviorFactory.hpp>
#include <engine/GameObject/Management/Abstractions/IGameObjectFactory.hpp>
#include <engine/GameObject/Management/Core/Abstractions/IGameObjectDeleteObserver.hpp>

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
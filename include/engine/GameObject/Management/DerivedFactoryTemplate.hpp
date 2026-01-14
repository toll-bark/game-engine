#ifndef engine_GameObject_Management_DerivedFactoryTemplate
#define engine_GameObject_Management_DerivedFactoryTemplate

#include <vector>

#include <engine/GameObject/Management/GameObjectFactoryTemplate.hpp>

namespace engine
{
	template <class T>
	class DerivedFactoryTemplate : public GameObjectFactoryTemplate<T>
	{
	protected:
		AbstractGameObjectManager& gom;
	public:
		DerivedFactoryTemplate<T>(AbstractGameObjectManager& gom) : GameObjectFactoryTemplate<T>(gom), gom(gom) {}

		virtual void onNext(int id) override 
		{ 
			if (this->objects.count(id) > 0) 
			{ 
				remove(id);
				this->objects.erase(id); 
			}
		}

		virtual void remove(int id) = 0;

		virtual ~DerivedFactoryTemplate<T>() = default;
	};
}

#endif
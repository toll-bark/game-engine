#ifndef engine_IGameObjectFactory
#define engine_IGameObjectFactory

#include <vector>
#include <unordered_map>

#include <engine/GameObject/Management/Abstractions/AbstractGameObjectManager.hpp>
#include <engine/GameObject/Management/Abstractions/IGameObjectDeleteObserver.hpp>

namespace engine
{
	template <class T>
	class GameObjectFactoryTemplate : public IGameObjectDeleteObserver
	{
	protected:
		std::unordered_map<int, T*> objects = {};
	public:
		GameObjectFactoryTemplate(AbstractGameObjectManager& gom) { gom.enroll(*this); }
		std::vector<T*> getAll(void)
		{
			std::vector<T*> res = {};
			for (std::pair<int, T*> kvp : objects) { res.push_back(kvp.second); }
			return res;
		}
		~GameObjectFactoryTemplate<T>() = default;
	};
}

#endif
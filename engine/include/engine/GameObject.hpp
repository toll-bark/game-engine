#ifndef engine_GameObject
#define engine_GameObject

namespace engine
{
	class GameObject
	{
	public:
		int id;
		GameObject(int id) { this->id = id; }
	};
}

#endif
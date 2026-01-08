#ifndef engine_DefaultPlatformFactory
#define engine_DefualtPlatformFactory

#include <engine/GameObject/Management/Core/Abstractions/AbstractDrawableFactory.hpp>
#include <engine/GameObject/Management/Core/Abstractions/AbstractPlatformFactory.hpp>

namespace engine
{
    class DefaultPlatformFactory : public AbstractPlatformFactory
    {
    private:
        std::unordered_map<int, Platform*> trackedObjects = {};
        AbstractGameObjectManager& gom;
        AbstractDrawableFactory& drawableFactory;
    public:
        DefaultPlatformFactory(AbstractGameObjectManager& gom, AbstractDrawableFactory& drawableFactory)
            : AbstractPlatformFactory(gom), gom(gom), drawableFactory(drawableFactory) {}
        virtual Platform& create(sf::Vector2f size, sf::Vector2f position) override;
        virtual std::vector<Platform*> getAll(void) override;
        virtual void onNext(int) override;
        ~DefaultPlatformFactory();
    };
}

#endif
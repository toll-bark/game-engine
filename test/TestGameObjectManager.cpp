#include <engine/GameObject/Management/Core/DefaultDrawableFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultGameObjectManager.hpp>
#include <engine/GameObject/Management/Core/DefaultPlatformFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultPlayerFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultUpdateableFactory.hpp>

#include <gtest/gtest.h>

TEST(TestGameObjectManager, TestPlatformCreate)
{
    {
        engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
        engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
        engine::AbstractPlatformFactory* platformFactory = new engine::DefaultPlatformFactory(*gom, *drawableFactory);
        
        engine::Platform& platform = platformFactory->create({500, 100}, {0, 0});
        
        ASSERT_EQ(1, platformFactory->getAll().size());
        ASSERT_EQ(&platform, platformFactory->getAll()[0]);
        
        ASSERT_EQ(1, drawableFactory->getAll().size());
        ASSERT_EQ(&platform, dynamic_cast<engine::Platform*>(drawableFactory->getAll()[0]));

        delete platformFactory;
        delete drawableFactory;
        delete gom;
    }
}

TEST(TestGameObjectManager, TestPlayerCreate)
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::BehaviorFactoryTemplate<engine::IUpdateable>* updateableFactory = new engine::DefaultUpdateableFactory(*gom);
    engine::AbstractPlayerFactory* playerFactory = new engine::DefaultPlayerFactory(*gom, *drawableFactory, *updateableFactory);

    engine::Player& player = playerFactory->create({0, 0});

    ASSERT_EQ(1, playerFactory->getAll().size());
    ASSERT_EQ(&player, playerFactory->getAll()[0]);

    ASSERT_EQ(1, drawableFactory->getAll().size());
    ASSERT_EQ(&player, drawableFactory->getAll()[0]);

    ASSERT_EQ(1, updateableFactory->getAll().size());
    ASSERT_EQ(&player, updateableFactory->getAll()[0]);

    delete playerFactory;
    delete updateableFactory;
    delete drawableFactory;
    delete gom;
}

TEST(TestGameObjectManager, TestCompoundCreate)
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::BehaviorFactoryTemplate<engine::IUpdateable>* updateableFactory = new engine::DefaultUpdateableFactory(*gom);

    engine::AbstractPlatformFactory* platformFactory = new engine::DefaultPlatformFactory(*gom, *drawableFactory);
    engine::AbstractPlayerFactory* playerFactory = new engine::DefaultPlayerFactory(*gom, *drawableFactory, *updateableFactory);

    engine::Platform& platform1 = platformFactory->create({500, 100}, {0, 0}),
        platform2 = platformFactory->create({250, 50}, {100, 100}),
        platform3 = platformFactory->create({250, 50}, {100, 500});

    engine::Player& player1 = playerFactory->create({0, 0}), 
        player2 = playerFactory->create({0, 0});

    std::set<int> idSet = { platform1.id, platform2.id, platform3.id, player1.id, player2.id };
    ASSERT_EQ(5, idSet.size());

    ASSERT_EQ(3, platformFactory->getAll().size());
    ASSERT_EQ(2, playerFactory->getAll().size());
    ASSERT_EQ(5, drawableFactory->getAll().size());
    ASSERT_EQ(2, updateableFactory->getAll().size());

    delete platformFactory;
    delete playerFactory;
    delete updateableFactory;
    delete drawableFactory;
    delete gom;
}

TEST(TestGameObjectManager, TestPlatformDelete)
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::AbstractPlatformFactory* platformFactory = new engine::DefaultPlatformFactory(*gom, *drawableFactory);

    engine::Platform& platform = platformFactory->create({500, 100}, {0, 0});

    ASSERT_EQ(1, platformFactory->getAll().size());
    ASSERT_EQ(&platform, platformFactory->getAll()[0]);

    ASSERT_EQ(1, drawableFactory->getAll().size());
    ASSERT_EQ(&platform, dynamic_cast<engine::Platform*>(drawableFactory->getAll()[0]));

    gom->deleteGameObject(platform.id);
    
    ASSERT_EQ(0, drawableFactory->getAll().size());
    ASSERT_EQ(0, platformFactory->getAll().size());

    delete platformFactory;
    delete drawableFactory;
    delete gom;
}

TEST(TestGameObjectManager, TestPlayerDelete)
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::BehaviorFactoryTemplate<engine::IUpdateable>* updateableFactory = new engine::DefaultUpdateableFactory(*gom);
    engine::AbstractPlayerFactory* playerFactory = new engine::DefaultPlayerFactory(*gom, *drawableFactory, *updateableFactory);

    engine::Player& player = playerFactory->create({0, 0});

    ASSERT_EQ(1, playerFactory->getAll().size());
    ASSERT_EQ(&player, playerFactory->getAll()[0]);

    ASSERT_EQ(1, drawableFactory->getAll().size());
    ASSERT_EQ(&player, drawableFactory->getAll()[0]);

    ASSERT_EQ(1, updateableFactory->getAll().size());
    ASSERT_EQ(&player, updateableFactory->getAll()[0]);

    gom->deleteGameObject(player.id);

    ASSERT_EQ(0, drawableFactory->getAll().size());
    ASSERT_EQ(0, updateableFactory->getAll().size());
    ASSERT_EQ(0, playerFactory->getAll().size());

    delete playerFactory;
    delete drawableFactory;
    delete updateableFactory;
    delete gom;
}

TEST(TestGameObjectManager, TestCompoundDelete)
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::BehaviorFactoryTemplate<engine::IUpdateable>* updateableFactory = new engine::DefaultUpdateableFactory(*gom);

    engine::AbstractPlatformFactory* platformFactory = new engine::DefaultPlatformFactory(*gom, *drawableFactory);
    engine::AbstractPlayerFactory* playerFactory = new engine::DefaultPlayerFactory(*gom, *drawableFactory, *updateableFactory);

    engine::Platform& platform1 = platformFactory->create({500, 100}, {0, 0}),
        platform2 = platformFactory->create({250, 50}, {100, 100}),
        platform3 = platformFactory->create({250, 50}, {100, 500});

    engine::Player& player1 = playerFactory->create({0, 0}), 
        player2 = playerFactory->create({0, 0});

    ASSERT_EQ(3, platformFactory->getAll().size());
    ASSERT_EQ(2, playerFactory->getAll().size());
    ASSERT_EQ(5, drawableFactory->getAll().size());
    ASSERT_EQ(2, updateableFactory->getAll().size());

    gom->deleteGameObject(platform3.id);

    ASSERT_EQ(2, platformFactory->getAll().size());
    ASSERT_EQ(2, playerFactory->getAll().size());
    ASSERT_EQ(4, drawableFactory->getAll().size());
    ASSERT_EQ(2, updateableFactory->getAll().size());

    gom->deleteGameObject(player2.id);

    ASSERT_EQ(2, platformFactory->getAll().size());
    ASSERT_EQ(1, playerFactory->getAll().size());
    ASSERT_EQ(3, drawableFactory->getAll().size());
    ASSERT_EQ(1, updateableFactory->getAll().size());

    gom->deleteGameObject(platform2.id);
    gom->deleteGameObject(platform1.id);

    ASSERT_EQ(0, platformFactory->getAll().size());
    ASSERT_EQ(1, playerFactory->getAll().size());
    ASSERT_EQ(1, drawableFactory->getAll().size());
    ASSERT_EQ(1, updateableFactory->getAll().size());

    gom->deleteGameObject(player1.id);

    ASSERT_EQ(0, platformFactory->getAll().size());
    ASSERT_EQ(0, playerFactory->getAll().size());
    ASSERT_EQ(0, drawableFactory->getAll().size());
    ASSERT_EQ(0, updateableFactory->getAll().size());

    delete platformFactory;
    delete playerFactory;
    delete updateableFactory;
    delete drawableFactory;
    delete gom;
}
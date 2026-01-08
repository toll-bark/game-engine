#include <engine/GameObject/Derived/Player.hpp>
#include <engine/GameObject/Management/Core/DefaultDrawableFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultGameObjectManager.hpp>
#include <engine/GameObject/Management/Core/DefaultPlatformFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultPlayerFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultUpdateableFactory.hpp>

int main()
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::BehaviorFactoryTemplate<engine::IUpdateable>* updateableFactory = new engine::DefaultUpdateableFactory(*gom);
    engine::AbstractPlatformFactory* platformFactory = new engine::DefaultPlatformFactory(*gom, *drawableFactory);
    engine::AbstractPlayerFactory* playerFactory = new engine::DefaultPlayerFactory(*gom, *drawableFactory, *updateableFactory);

    bool playerCanJump = false;
    std::unordered_map<sf::Keyboard::Key, bool> heldKeys = {};

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    engine::Platform& platform = platformFactory->create({1500, 10}, {210, 1000});
    engine::Player& player = playerFactory->create({935, 500});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            else if (event->is<sf::Event::KeyPressed>())
            {
                switch(event->getIf<sf::Event::KeyPressed>()->code)
                {
                    case sf::Keyboard::Key::Left:
                        player.velocity.x += -5;
                        break;
                    case sf::Keyboard::Key::Right:
                        player.velocity.x += 5;
                        break;
                    case sf::Keyboard::Key::Space:
                        if (playerCanJump) { player.velocity.y += -10; }
                        break;
                    default:
                        break;
                }
            }
            else if (event->is<sf::Event::KeyReleased>())
            {
                switch(event->getIf<sf::Event::KeyReleased>()->code)
                {
                    case sf::Keyboard::Key::Left:
                        player.velocity.x -= -5;
                        break;
                    case sf::Keyboard::Key::Right:
                        player.velocity.x -= 5;
                        break;
                    default:
                        break;
                }
            }
        }

        for (auto updateable : updateableFactory->getAll()) { updateable->update(); }

        if (player.boundingBox.getGlobalBounds().findIntersection(platform.boundingBox.getGlobalBounds()).has_value())
        {
            player.velocity.y = 0;

            auto top_of_platform = platform.boundingBox.getPosition().y;
            auto bottom_of_player = player.boundingBox.getPosition().y + player.boundingBox.getSize().y;
            auto diff = top_of_platform - bottom_of_player;
            player.boundingBox.setPosition(player.boundingBox.getPosition() + sf::Vector2f(0, diff));
            playerCanJump = true;
        }
        else { playerCanJump = false; }

        window.clear();
        for (auto drawable : drawableFactory->getAll()) { drawable->draw(window); }
        window.display();
    }

    delete playerFactory;
    delete platformFactory;
    delete drawableFactory;
    delete updateableFactory;
    delete gom;
}
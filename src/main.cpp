#include <engine/GameObject/Derived/Player.hpp>
#include <engine/GameObject/Management/Core/DefaultDrawableFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultGameObjectManager.hpp>
#include <engine/GameObject/Management/Core/DefaultPlatformFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultPlayerFactory.hpp>
#include <engine/GameObject/Management/Core/DefaultUpdateableFactory.hpp>

engine::Player* player = nullptr;
bool player_can_jump = false;

std::unordered_map<sf::Keyboard::Key, bool> heldKeys = {};

static void handleKeyPress(const sf::Event::KeyPressed* event)
{
    if (player == nullptr) return;

    switch(event->code)
    {
        case sf::Keyboard::Key::Left:
            player->velocity.x += -5;
            break;
        case sf::Keyboard::Key::Right:
            player->velocity.x += 5;
            break;
        case sf::Keyboard::Key::Space:
            if (player_can_jump) { player->velocity.y += -10; }
            break;
        default:
            break;
    }
}

static void handleKeyRelease(const sf::Event::KeyReleased* event)
{
    if (player == nullptr) return;

    switch(event->code)
    {
        case sf::Keyboard::Key::Left:
            player->velocity.x -= -5;
            break;
        case sf::Keyboard::Key::Right:
            player->velocity.x -= 5;
            break;
        default:
            break;
    }
}

int main()
{
    engine::AbstractGameObjectManager* gom = new engine::DefaultGameObjectManager();
    engine::BehaviorFactoryTemplate<engine::IDrawable>* drawableFactory = new engine::DefaultDrawableFactory(*gom);
    engine::BehaviorFactoryTemplate<engine::IUpdateable>* updateableFactory = new engine::DefaultUpdateableFactory(*gom);
    engine::AbstractPlatformFactory* platformFactory = new engine::DefaultPlatformFactory(*gom, *drawableFactory);
    engine::AbstractPlayerFactory* playerFactory = new engine::DefaultPlayerFactory(*gom, *drawableFactory, *updateableFactory);

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    auto platform = platformFactory->create({1500, 10}, {210, 1000});
    player = &playerFactory->create({935, 500});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }

            if (event->is<sf::Event::KeyPressed>()) { handleKeyPress(event->getIf<sf::Event::KeyPressed>()); }
            if (event->is<sf::Event::KeyReleased>()) { handleKeyRelease(event->getIf<sf::Event::KeyReleased>()); }
        }

        for (auto updateable : updateableFactory->getAll()) { updateable->update(); }

        if (player->boundingBox.getGlobalBounds().findIntersection(platform.boundingBox.getGlobalBounds()).has_value())
        {
            player->velocity.y = 0;

            auto top_of_platform = platform.boundingBox.getPosition().y;
            auto bottom_of_player = player->boundingBox.getPosition().y + player->boundingBox.getSize().y;
            auto diff = top_of_platform - bottom_of_player;
            player->boundingBox.setPosition(player->boundingBox.getPosition() + sf::Vector2f(0, diff));
            player_can_jump = true;
        }
        else { player_can_jump = false; }

        window.clear();
        for (auto drawable : drawableFactory->getAll()) { drawable->draw(window); }
        window.display();
    }
}
#include "Player.hpp"
#include "Platform.hpp"

engine::Player* player = nullptr;
bool player_can_jump = false;

std::vector<engine::IDrawable*> drawables = {};

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
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    auto platform = engine::Platform(0, {1500, 10}, {210, 1000});
    drawables.push_back(&platform);

    auto playerEntity = engine::Player(1, {935, 500});
    player = &playerEntity;
    drawables.push_back(&playerEntity);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }

            if (event->is<sf::Event::KeyPressed>()) { handleKeyPress(event->getIf<sf::Event::KeyPressed>()); }
            if (event->is<sf::Event::KeyReleased>()) { handleKeyRelease(event->getIf<sf::Event::KeyReleased>()); }
        }

        // handle gravity
        playerEntity.update();
        if (playerEntity.boundingBox.getGlobalBounds().findIntersection(platform.boundingBox.getGlobalBounds()).has_value())
        {
            playerEntity.velocity.y = 0;

            auto top_of_platform = platform.boundingBox.getPosition().y;
            auto bottom_of_player = playerEntity.boundingBox.getPosition().y + playerEntity.boundingBox.getSize().y;
            auto diff = top_of_platform - bottom_of_player;
            playerEntity.boundingBox.setPosition(playerEntity.boundingBox.getPosition() + sf::Vector2f(0, diff));
            player_can_jump = true;
        }
        else { player_can_jump = false; }

        window.clear();
        for (auto drawable : drawables) { drawable->draw(window); }
        window.display();
    }
}
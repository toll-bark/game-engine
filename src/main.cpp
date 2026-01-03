#include "Player.hpp"
#include "Platform.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    std::vector<engine::IDrawable*> drawables = {};

    auto platform = engine::Platform({1500, 10}, {210, 1000});
    drawables.push_back(&platform);

    auto player = engine::Player({935, 500});
    drawables.push_back(&player);

    bool player_can_jump = false;

    std::unordered_map<sf::Keyboard::Key, bool> heldKeys = {};


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>()) 
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
                        if (player_can_jump) { player.velocity.y += -10; }
                        break;
                    default:
                        break;
                }
            }
            if (event->is<sf::Event::KeyReleased>()) {
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

        // handle gravity
        player.update();
        if (player.boundingBox.getGlobalBounds().findIntersection(platform.boundingBox.getGlobalBounds()).has_value())
        {
            player.velocity.y = 0;

            auto top_of_platform = platform.boundingBox.getPosition().y;
            auto bottom_of_player = player.boundingBox.getPosition().y + player.boundingBox.getSize().y;
            auto diff = top_of_platform - bottom_of_player;
            player.boundingBox.setPosition(player.boundingBox.getPosition() + sf::Vector2f(0, diff));
            player_can_jump = true;
        }
        else { player_can_jump = false; }

        window.clear();
        for (auto drawable : drawables) { drawable->draw(window); }
        window.display();
    }
}
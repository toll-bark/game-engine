#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    auto player = sf::RectangleShape({50, 100});
    player.setFillColor(sf::Color::Magenta);
    player.setPosition({935, 500});
    bool player_can_jump = false;

    sf::Vector2f player_velocity(0, 0);

    auto platform = sf::RectangleShape({1500, 10});
    platform.setPosition({210, 1000});

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
                        player_velocity.x += -5;
                        break;
                    case sf::Keyboard::Key::Right:
                        player_velocity.x += 5;
                        break;
                    case sf::Keyboard::Key::Space:
                        if (player_can_jump) { player_velocity.y += -10; }
                        break;
                    default:
                        break;
                }
            }
            if (event->is<sf::Event::KeyReleased>()) {
                switch(event->getIf<sf::Event::KeyReleased>()->code)
                {
                    case sf::Keyboard::Key::Left:
                        player_velocity.x -= -5;
                        break;
                    case sf::Keyboard::Key::Right:
                        player_velocity.x -= 5;
                        break;
                    default:
                        break;
                }
            }
        }

        // handle gravity
        player_velocity.y += 10. / 144;
        player.setPosition(player.getPosition() + player_velocity);
        if (player.getGlobalBounds().findIntersection(platform.getGlobalBounds()).has_value())
        {
            player_velocity.y = 0;

            auto top_of_platform = platform.getPosition().y;
            auto bottom_of_player = player.getPosition().y + player.getSize().y;
            auto diff = top_of_platform - bottom_of_player;
            player.setPosition(player.getPosition() + sf::Vector2f(0, diff));
            player_can_jump = true;
        }
        else { player_can_jump = false; }

        window.clear();
        
        window.draw(platform);
        window.draw(player);
        
        window.display();
    }
}
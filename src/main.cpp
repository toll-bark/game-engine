#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    auto player = sf::RectangleShape({50, 100});
    player.setFillColor(sf::Color::Magenta);
    player.setPosition({935, 500});

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

            if (event->is<sf::Event::KeyPressed>()) { heldKeys[event->getIf<sf::Event::KeyPressed>()->code] = true; }
            if (event->is<sf::Event::KeyReleased>()) { heldKeys[event->getIf<sf::Event::KeyReleased>()->code] = false; }
        }

        if (heldKeys.count(sf::Keyboard::Key::Left) > 0 && heldKeys[sf::Keyboard::Key::Left]) player.setPosition(player.getPosition() + sf::Vector2f(-5, 0));
        if (heldKeys.count(sf::Keyboard::Key::Right) > 0 && heldKeys[sf::Keyboard::Key::Right]) player.setPosition(player.getPosition() + sf::Vector2f(5, 0));

        window.clear();
        
        window.draw(platform);
        window.draw(player);
        
        window.display();
    }
}
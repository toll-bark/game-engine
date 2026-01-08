#include <engine/Player.hpp>

engine::Player::Player(int id, sf::Vector2f position) 
    : engine::GameObject(id)
{
    boundingBox = sf::RectangleShape({50, 100});
    boundingBox.setPosition(position);
    boundingBox.setFillColor(sf::Color::Magenta);
}

void engine::Player::update()
{
    velocity.y += 10. / 144;
    boundingBox.setPosition(boundingBox.getPosition() + velocity);
}

void engine::Player::draw(sf::RenderTarget& target) { target.draw(boundingBox); }
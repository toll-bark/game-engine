#include "Player.hpp"

engine::Player::Player(sf::Vector2f position)
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
#include <Player.h>

RB_NAMESPACE_BEGIN

Player::Player() : speed(0.05f), bubble_power(1), bubble_count(1)
{
    inst = {10.0f, 10.0f, this->size, this->size};
}
Player::Player(Pos pos) : speed(0.05f), bubble_power(1), bubble_count(1)
{
    inst = {pos.x, pos.y, this->size, this->size};
}
Player::Player(float speed, uint8_t bubble_power, uint8_t bubble_count) : speed(speed), bubble_power(bubble_power), bubble_count(bubble_count)
{
    inst = {10.0f, 10.0f, this->size, this->size};
}

void Player::setSpeed(float speed)
{
    this->speed = speed;
}
float Player::getSpeed() const
{
    return this->speed;
}

void Player::setBubblePower(uint8_t bubble_power)
{
    this->bubble_power = bubble_power;
}
uint8_t Player::getBubblePower() const
{
    return this->bubble_power;
}

void Player::setBubbleCount(uint8_t bubble_count)
{
    this->bubble_count = bubble_count;
}
uint8_t Player::getBubbleCount() const
{
    return this->bubble_count;
}

void Player::setPos(Pos pos)
{
    this->inst.x = pos.x;
    this->inst.y = pos.y;
}
void Player::updatePos(Pos pos)
{
    this->inst.x += pos.x;
    this->inst.y += pos.y;
}
Pos Player::getPos() const
{
    return {this->inst.x, this->inst.y};
}
Pos Player::getCenterPos() const
{
    return {this->inst.x + (this->getSize() / 2), this->inst.y + (this->getSize() / 2)};
}

const float Player::getSize() const
{
    return this->size;
}

RB_NAMESPACE_END
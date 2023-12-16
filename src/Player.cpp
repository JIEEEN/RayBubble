#include <Player.h>

RB_NAMESPACE_BEGIN

Player::Player() : speed(0.05f)
{
    inst = {10.0f, 10.0f, this->size, this->size};
}
Player::Player(float speed) : speed(speed)
{
    inst = {10.0f, 10.0f, this->size, this->size};
}
Player::Player(Pos pos) : speed(0.05f)
{
    inst = {pos.x, pos.y, this->size, this->size};
}
Player::Player(float speed, Pos pos) : speed(speed)
{
    inst = {pos.x, pos.y, this->size, this->size};
}

void Player::setSpeed(float speed)
{
    this->speed = speed;
}
float Player::getSpeed() const
{
    return this->speed;
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
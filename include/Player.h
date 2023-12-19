#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <stdint.h>
#include <common.h>
#include <namespace.h>
#include <type.h>

#include "raylib.h"

RB_NAMESPACE_BEGIN

class Player
{
private:
    const float size = 30.0f;
    float speed;
    uint8_t bubble_power;
    uint8_t bubble_count;

public:
    Rectangle inst;

    Player();
    Player(Pos pos);
    Player(float speed, uint8_t bubble_power, uint8_t bubble_count);
    ~Player(){};

    void setSpeed(float);
    float getSpeed() const;
    void setBubblePower(uint8_t);
    uint8_t getBubblePower() const;
    void setBubbleCount(uint8_t);
    uint8_t getBubbleCount() const;
    void setPos(Pos pos);
    void updatePos(Pos pos);
    Pos getPos() const;
    Pos getCenterPos() const;
    const float getSize() const;
};

RB_NAMESPACE_END

#endif // __PLAYER_H_
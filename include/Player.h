#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <stdint.h>
#include <common.h>
#include <namespace.h>
#include <type.h>

#include "raylib.h"

RB_NAMESPACE_BEGIN

class Player{
    private:
        const float size = 30.0f;
        float speed;
    public:
        Rectangle inst;

        Player();
        Player(float speed);
        Player(Pos pos);
        Player(float speed, Pos pos);
        ~Player(){};

        void setSpeed(float speed);
        float getSpeed() const;
        void updatePos(Pos pos);
        Pos getPos() const;
        const float getSize() const;
};

RB_NAMESPACE_END

#endif // __PLAYER_H_
#ifndef __INPUT_CONTROLLER_H_
#define __INPUT_CONTROLLER_H_

#include <common.h>
#include <namespace.h>
#include <Player.h>

#include "raylib.h"

RB_NAMESPACE_BEGIN

class InputController{
    // private:
    public:
        void keyInputProcess(Player& p);
};

RB_NAMESPACE_END

#endif // __INPUT_CONTROLLER_H_
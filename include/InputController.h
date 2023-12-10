#ifndef __INPUT_CONTROLLER_H_
#define __INPUT_CONTROLLER_H_

#include <common.h>
#include <namespace.h>
#include <Player.h>
#include <utils.h>
#include <type.h>

#include "raylib.h"

RB_NAMESPACE_BEGIN

class InputController
{
    // private:
public:
    void keyInputProcess(Player &, map_t &, Config &);
    void playerMove(Player &, map_t &, Config &);
};

RB_NAMESPACE_END

#endif // __INPUT_CONTROLLER_H_
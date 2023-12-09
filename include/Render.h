#ifndef __RENDER_H_
#define __RENDER_H_

#include <common.h>
#include <namespace.h>
#include <Player.h>
#include <Map.h>
#include "raylib.h"

RB_NAMESPACE_BEGIN

class Render{
    private:
    public:
        void playerRender(Player&, Color);
        void backgroundRender(Color);
        void mapRender(map_t&, const int, const uint8_t, const uint8_t);
};

RB_NAMESPACE_END

#endif // __RENDER_H_
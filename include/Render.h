#ifndef __RENDER_H_
#define __RENDER_H_

#include <common.h>
#include <namespace.h>
#include <Player.h>
#include <Map.h>
#include "raylib.h"

RB_NAMESPACE_BEGIN

class Render
{
private:
public:
    void playerRender(Player &, Color);
    void backgroundRender(Color);
    void mapRender(map_t &, Config &);
    void bubbleRender(const mapidx_t &, Config &);
    void bubbleRenderErase(Player&, map_t &, const mapidx_t);
};

RB_NAMESPACE_END

#endif // __RENDER_H_
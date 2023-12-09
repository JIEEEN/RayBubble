#include "raylib.h"
#include <common.h>
#include <namespace.h>
#include <Player.h>
#include <InputController.h>
#include <Render.h>
#include <utils.h>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define P1_COLOR RED
#define P2_COLOR BLUE
#define BG_COLOR RAYWHITE

using namespace RB_NAMESPACE;

int main(){
    const char* window_name = "GAME";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, window_name);

    Player _p1;
    Map ctr_map;

    Render renderer;
    InputController ctr_input;

    ctr_map.mapInit();
    map_t _map1 = ctr_map.getMap(1);

    std::tuple<float, float> map_start_pos = getMapStartTuple(SCREEN_WIDTH, SCREEN_HEIGHT, _p1.getSize());

    while(!WindowShouldClose()){
        ctr_input.keyInputProcess(_p1);

        BeginDrawing();
            renderer.backgroundRender(BG_COLOR);
            renderer.mapRender(_map1, _p1.getSize(), static_cast<uint8_t>(std::get<0>(map_start_pos)), static_cast<uint8_t>(std::get<1>(map_start_pos)));
            renderer.playerRender(_p1, P1_COLOR);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

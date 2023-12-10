#include "raylib.h"
#include <common.h>
#include <namespace.h>
#include <Player.h>
#include <InputController.h>
#include <Render.h>
#include <utils.h>
#include <Config.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define P1_COLOR RED
#define P2_COLOR BLUE
#define BG_COLOR RAYWHITE

using namespace RB_NAMESPACE;

int main(){
    const char* window_name = "GAME";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, window_name);

    Config cfg = {
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        35.0f, // map_block_size
        30.0f, // player_size
        10.0f, // p1_x
        10.0f, // p1_y
        10.0f, // p2_x
        10.0f // p2_y
    };

    Map ctr_map(cfg.map_block_size);
    Player _p1(0.05f, {cfg.p1_pos_x, cfg.p1_pos_y});

    Render renderer;
    InputController ctr_input;

    ctr_map.mapInit();
    map_t& _map1 = ctr_map.getMap(1);

    std::tuple<float, float> map_start_pos = getMapStartTuple(SCREEN_WIDTH, SCREEN_HEIGHT, ctr_map.getBlockSize());
    std::tuple<float, float> random_player_pos = randomizePlayerPos(_map1, ctr_map.getBlockSize(), std::get<0>(map_start_pos), std::get<1>(map_start_pos));

    _p1.setPos({std::get<0>(random_player_pos), std::get<1>(random_player_pos)});


    while(!WindowShouldClose()){
        ctr_input.keyInputProcess(_p1);

        BeginDrawing();
            renderer.backgroundRender(BG_COLOR);
            renderer.mapRender(
                _map1, ctr_map.getBlockSize(),
                static_cast<uint8_t>(std::get<0>(map_start_pos)), 
                static_cast<uint8_t>(std::get<1>(map_start_pos))
            );
            renderer.playerRender(_p1, P1_COLOR);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

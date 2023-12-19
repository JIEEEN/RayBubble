#include "raylib.h"
#include <Player.h>
#include <InputController.h>
#include <Render.h>
#include <utils.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define P1_COLOR RED
#define P2_COLOR BLUE
#define BG_COLOR RAYWHITE

using namespace RB_NAMESPACE;



int main(){
    const char* window_name = "GAME";
    Config cfg = {
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        35.0f, // map_block_size
        30.0f, // player_size
        0.0f, // map_start_pos_x
        0.0f, // map_start_pos_y
        0.0f, // p1_pos_x
        0.0f, // p1_pos_y
        0.0f, // p2_pos_x
        0.0f // p2_pos_y
    }; 

    InitWindow(cfg.screen_width, cfg.screen_height, window_name);


    Map ctr_map(cfg.map_block_size);
    Player _p1;

    Render renderer;
    InputController ctr_input;

    ctr_map.mapInit();
    map_t& _map = ctr_map.getMap(3);

    std::tuple<float, float> map_start_pos = getMapStartTuple(cfg);
    cfg.map_start_pos_x = std::get<0>(map_start_pos);
    cfg.map_start_pos_y = std::get<1>(map_start_pos);

    std::tuple<float, float> random_player_pos = randomizePlayerPos(_map, cfg);
    cfg.p1_pos_x = std::get<0>(random_player_pos);
    cfg.p1_pos_y = std::get<1>(random_player_pos);

    _p1.setPos({cfg.p1_pos_x, cfg.p1_pos_y});

    while(!WindowShouldClose()){
        ctr_input.keyInputProcess(
            _p1,
            _map,
            cfg
        );
 
        BeginDrawing();
            renderer.mapRender(
                _map, 
                cfg
            );
            renderer.backgroundRender(BG_COLOR);
            renderer.playerRender(_p1, P1_COLOR);

            const mapidx_t bubble_map_idx = realCenter2Index(_p1.getPos(), cfg);
            if(!_map[std::get<1>(bubble_map_idx)][std::get<0>(bubble_map_idx)] && IsKeyPressed(KEY_SPACE) && _p1.getBubbleCount() >= 1){
                _map[std::get<1>(bubble_map_idx)][std::get<0>(bubble_map_idx)] = 1; // apply bubble to map index
                _p1.setBubbleCount(_p1.getBubbleCount() - 1);

                std::thread bubble_timer(std::bind(&Render::bubbleRenderErase, &renderer, std::ref(_p1), std::ref(_map), bubble_map_idx)); // bubble eraser
                bubble_timer.detach();
            }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

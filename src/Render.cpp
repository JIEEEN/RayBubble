#include <Render.h>

RB_NAMESPACE_BEGIN

void Render::playerRender(Player& p, Color color){
    DrawRectangleRec(p.inst, color);
}
void Render::backgroundRender(Color color){
    ClearBackground(color);
}
void Render::mapRender(map_t& map, const int block_size, const uint8_t map_start_pos_x, const uint8_t map_start_pos_y){
    for(int i=0; i<map.size(); ++i){
        for(int j=0; j<map[i].size(); ++j){
            if(map[i][j] == 0){
                DrawRectangle(
                    map_start_pos_x+block_size*j, map_start_pos_y+block_size*i, 
                    block_size, block_size, RAYWHITE
                );
                DrawRectangleLines(
                    map_start_pos_x+block_size*j, map_start_pos_y+block_size*i,
                    block_size, block_size, LIGHTGRAY
                );
            }
            else if(map[i][j] == 1){
                DrawRectangle(
                    map_start_pos_x+block_size*j, map_start_pos_y+block_size*i, 
                    block_size, block_size, BROWN
                );
            }
        }
    }
}

RB_NAMESPACE_END
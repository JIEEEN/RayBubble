#include <Render.h>

RB_NAMESPACE_BEGIN

void Render::playerRender(Player& p, Color color){
    DrawRectangleRec(p.inst, color);
}
void Render::backgroundRender(Color color){
    ClearBackground(color);
}
void Render::mapRender(map_t& map, Config cfg){
    for(int i=0; i<map.size(); ++i){
        for(int j=0; j<map[i].size(); ++j){
            if(map[i][j] == 0){
                DrawRectangle(
                    cfg.map_start_pos_x + cfg.map_block_size * j, cfg.map_start_pos_y + cfg.map_block_size * i, 
                    cfg.map_block_size, cfg.map_block_size, RAYWHITE
                );
                DrawRectangleLines(
                    cfg.map_start_pos_x+cfg.map_block_size*j, cfg.map_start_pos_y+cfg.map_block_size*i,
                    cfg.map_block_size, cfg.map_block_size, LIGHTGRAY
                );
            }
            else if(map[i][j] == 1){
                DrawRectangle(
                    cfg.map_start_pos_x + cfg.map_block_size * j, cfg.map_start_pos_y + cfg.map_block_size * i, 
                    cfg.map_block_size, cfg.map_block_size, BROWN
                );
            }
        }
    }
}

RB_NAMESPACE_END
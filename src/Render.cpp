#include <Render.h>

RB_NAMESPACE_BEGIN

void Render::playerRender(Player &p, Color color)
{
    DrawRectangleRec(p.inst, color);
}
void Render::backgroundRender(Color color)
{
    ClearBackground(color);
}
void Render::mapRender(map_t &map, Config& cfg)
{
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[i].size(); ++j)
        {
            if (map[i][j] == 0)
            {
                DrawRectangle(
                    cfg.map_start_pos_x + cfg.map_block_size * j, cfg.map_start_pos_y + cfg.map_block_size * i,
                    cfg.map_block_size, cfg.map_block_size, RAYWHITE);
                DrawRectangleLines(
                    cfg.map_start_pos_x + cfg.map_block_size * j, cfg.map_start_pos_y + cfg.map_block_size * i,
                    cfg.map_block_size, cfg.map_block_size, LIGHTGRAY);
            }
            else if (map[i][j] == 1)
            {
                this->bubbleRender(std::make_tuple(static_cast<uint8_t>(j), static_cast<uint8_t>(i)), cfg);
            }
            else if (map[i][j] == 2)
            {
                DrawRectangle(
                    cfg.map_start_pos_x + cfg.map_block_size * j, cfg.map_start_pos_y + cfg.map_block_size * i,
                    cfg.map_block_size, cfg.map_block_size, BROWN);
            }
        }
    }
}

void Render::bubbleRender(const mapidx_t &map_pos, Config& cfg){
    DrawCircleGradient(
        cfg.map_block_size / 2 + cfg.map_start_pos_x + cfg.map_block_size * std::get<0>(map_pos), cfg.map_block_size / 2 + cfg.map_start_pos_y + cfg.map_block_size * std::get<1>(map_pos),
        cfg.map_block_size / 2 - 1.0f, SKYBLUE, BLUE
    );
    DrawRectangleLines(
        cfg.map_start_pos_x + cfg.map_block_size * std::get<0>(map_pos), cfg.map_start_pos_y + cfg.map_block_size * std::get<1>(map_pos),
        cfg.map_block_size, cfg.map_block_size, LIGHTGRAY
    );
}

void Render::bubbleRenderErase(map_t& map, const mapidx_t map_pos){
    std::this_thread::sleep_for(std::chrono::seconds(3)); // bubble wait for 3 seconds ... 
    map[std::get<1>(map_pos)][std::get<0>(map_pos)] = 0;
}

RB_NAMESPACE_END
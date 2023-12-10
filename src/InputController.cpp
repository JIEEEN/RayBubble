#include <InputController.h>

RB_NAMESPACE_BEGIN

void InputController::keyInputProcess(
    Player &p,
    map_t &map,
    Config &cfg)
{
    this->playerMove(p, map, cfg);
}

void InputController::playerMove(
    Player &p,
    map_t &map,
    Config &cfg)
{
    Pos pos = p.getPos();

    const std::tuple<uint8_t, uint8_t> player_map_idx = realCenter2Index(pos, cfg);

    uint8_t player_map_idx_x = std::get<0>(player_map_idx);
    uint8_t player_map_idx_y = std::get<1>(player_map_idx);

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
        Pos LT_pos = getBoxPoint(0, p);
        if(LT_pos.y <= cfg.map_start_pos_y)
            return;
        p.updatePos({0.0f, -p.getSpeed()});
    }
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        Pos LB_pos = getBoxPoint(1, p);
        if(LB_pos.y >= cfg.map_start_pos_y + cfg.map_block_size * 13) // 13 => block num of row
            return;
        p.updatePos({0.0f, +p.getSpeed()});
    }
    else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        Pos RT_pos = getBoxPoint(2, p);
        if(RT_pos.x >= cfg.map_start_pos_x + cfg.map_block_size * 15) // 15 => block num of column
            return;
        p.updatePos({+p.getSpeed(), 0.0f});
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        Pos LT_pos = getBoxPoint(0, p);
        if(LT_pos.x <= cfg.map_start_pos_x)
            return;
        p.updatePos({-p.getSpeed(), 0.0f});
    }
}

RB_NAMESPACE_END
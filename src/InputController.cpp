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

    const mapidx_t player_map_idx = realCenter2Index(pos, cfg);

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
        Pos LT_pos = getBoxPoint(0, p);
        Pos RT_pos = getBoxPoint(2, p);
        mapidx_t lt_map_idx = realPoint2Index({LT_pos.x, LT_pos.y - 0.5f}, cfg);
        mapidx_t rt_map_idx = realPoint2Index({RT_pos.x, RT_pos.y - 0.5f}, cfg);
        if(
            LT_pos.y > cfg.map_start_pos_y
            && (
                map[std::get<1>(player_map_idx)][std::get<0>(player_map_idx)] == 1
                || (map[std::get<1>(lt_map_idx)][std::get<0>(lt_map_idx)] <= 0
                && map[std::get<1>(rt_map_idx)][std::get<0>(rt_map_idx)] <= 0)
            )
        )
            p.updatePos({0.0f, -p.getSpeed()});
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        Pos LB_pos = getBoxPoint(1, p);
        Pos RB_pos = getBoxPoint(3, p);
        mapidx_t lb_map_idx = realPoint2Index({LB_pos.x, LB_pos.y + 0.5f}, cfg);
        mapidx_t rb_map_idx = realPoint2Index({RB_pos.x, RB_pos.y + 0.5f}, cfg);
        if(
            LB_pos.y < cfg.map_start_pos_y + cfg.map_block_size * 12.98
            && (
                map[std::get<1>(player_map_idx)][std::get<0>(player_map_idx)] == 1
                || (map[std::get<1>(lb_map_idx)][std::get<0>(lb_map_idx)] <= 0
                && map[std::get<1>(rb_map_idx)][std::get<0>(rb_map_idx)] <= 0)
            )
        ) // 13 => block num of row
            p.updatePos({0.0f, +p.getSpeed()});
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        Pos RT_pos = getBoxPoint(2, p);
        Pos RB_pos = getBoxPoint(3, p);
        mapidx_t rt_map_idx = realPoint2Index({RT_pos.x + 0.5f, RT_pos.y}, cfg);
        mapidx_t rb_map_idx = realPoint2Index({RB_pos.x + 0.5f, RB_pos.y}, cfg);
        if(
            RT_pos.x < cfg.map_start_pos_x + cfg.map_block_size * 15 
            && (
                map[std::get<1>(player_map_idx)][std::get<0>(player_map_idx)] == 1
                || (map[std::get<1>(rt_map_idx)][std::get<0>(rt_map_idx)] <= 0
                && map[std::get<1>(rb_map_idx)][std::get<0>(rb_map_idx)] <= 0)
            )
        ) // 15 => block num of column
            p.updatePos({+p.getSpeed(), 0.0f});
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        Pos LT_pos = getBoxPoint(0, p);
        Pos LB_pos = getBoxPoint(1, p);
        mapidx_t lt_map_idx = realPoint2Index({LT_pos.x - 0.5f, LT_pos.y}, cfg);
        mapidx_t lb_map_idx = realPoint2Index({LB_pos.x - 0.5f, LB_pos.y}, cfg);
        if(
            LT_pos.x > cfg.map_start_pos_x 
            && (
                map[std::get<1>(player_map_idx)][std::get<0>(player_map_idx)] == 1
                || (map[std::get<1>(lt_map_idx)][std::get<0>(lt_map_idx)] <= 0
                && map[std::get<1>(lb_map_idx)][std::get<0>(lb_map_idx)] <= 0)
            )
        )
            p.updatePos({-p.getSpeed(), 0.0f});
    }
}



RB_NAMESPACE_END
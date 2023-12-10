#include <InputController.h>

RB_NAMESPACE_BEGIN

void InputController::keyInputProcess(
    Player& p,
    map_t& map,
    Config& cfg
){
    this->playerMove(p, map, cfg);
}

void InputController::playerMove(
    Player& p,
    map_t& map,
    Config& cfg
){
    Pos pos = p.getPos();

    const std::tuple<uint8_t, uint8_t> player_map_idx = real2Index(pos, cfg);

    uint8_t player_map_idx_x = std::get<0>(player_map_idx);
    uint8_t player_map_idx_y = std::get<1>(player_map_idx);

    // std::cout << static_cast<int>(player_map_idx_x) << " " << static_cast<int>(player_map_idx_y) << "\n";

    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
        if(player_map_idx_y == 0) return;
        p.updatePos({0.0f, -p.getSpeed()});
    }
    else if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        if(player_map_idx_y == 12) return;
        p.updatePos({0.0f, +p.getSpeed()});
    }
    else if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        if(player_map_idx_x == 14) return;
        p.updatePos({+p.getSpeed(), 0.0f});
    }
    else if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        if(player_map_idx_x == 0) return;
        p.updatePos({-p.getSpeed(), 0.0f});
    }
}

RB_NAMESPACE_END
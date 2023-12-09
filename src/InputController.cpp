#include <InputController.h>

RB_NAMESPACE_BEGIN

void InputController::keyInputProcess(Player& p){
    // Player Move
    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
        p.updatePos({0.0f, -p.getSpeed()});
    }
    else if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        p.updatePos({0.0f, +p.getSpeed()});
    }
    else if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        p.updatePos({+p.getSpeed(), 0.0f});
    }
    else if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        p.updatePos({-p.getSpeed(), 0.0f});
    }
}

RB_NAMESPACE_END
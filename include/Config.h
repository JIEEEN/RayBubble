#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <common.h>
#include <namespace.h>

RB_NAMESPACE_BEGIN

typedef struct{
    uint16_t screen_width;
    uint16_t screen_height;
    float map_block_size;
    float player_size;
    float p1_pos_x;
    float p1_pos_y;
    float p2_pos_x;
    float p2_pos_y;
} Config;

RB_NAMESPACE_END

#endif // __CONFIG_H_
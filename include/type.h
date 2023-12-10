#ifndef __TYPE_H_
#define __TYPE_H_

typedef struct{
    float x;
    float y;
} Pos;

typedef struct{
    uint16_t screen_width;
    uint16_t screen_height;
    float map_block_size;
    float player_size;
    float map_start_pos_x;
    float map_start_pos_y;
    float p1_pos_x;
    float p1_pos_y;
    float p2_pos_x;
    float p2_pos_y;
} Config;

using map_t = std::vector<std::vector<uint8_t>>;

#endif // __TYPE_H_
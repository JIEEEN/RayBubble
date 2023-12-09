#ifndef __UTILS_H_
#define __UTILS_H_

#include <common.h>

const std::tuple<float, float>& getMapStartTuple(const int screen_width, const int screen_height, const int block_size){
    float center_width = screen_width/2;
    float center_height = screen_height/2;

    float half_block_size = block_size/2;
    float half_map_size_x = 7*block_size + half_block_size;
    float half_map_size_y = 6*block_size + half_block_size;

    return std::make_tuple(center_width - half_map_size_x, center_height - half_map_size_y);
}

#endif // __UTILS_H
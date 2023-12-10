#ifndef __UTILS_H_
#define __UTILS_H_

#include <common.h>
#include <type.h>

const std::tuple<float, float>& getMapStartTuple(const int screen_width, const int screen_height, const float block_size){
    float center_width = screen_width/2;
    float center_height = screen_height/2;

    float half_block_size = block_size/2;
    float half_map_size_x = 7*block_size + half_block_size;
    float half_map_size_y = 6*block_size + half_block_size;

    return std::make_tuple(center_width - half_map_size_x, center_height - half_map_size_y);
}

const std::tuple<float, float>& randomizePlayerPos(map_t& map, const float block_size, const float map_start_pos_x, const float map_start_pos_y){
    /**
     * @brief set Player Pos to Random where map data is Zero(movable area)
    */
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    auto findZeroIndex = [&](map_t& map){
        std::vector<int> indices;

        for(int i=0; i<map.size(); ++i){
            for(int j=0; j<map[0].size(); ++j){
                if(map[i][j] == 0) indices.push_back(i*15+j);
            }
        }

        return indices;
    };

    std::vector<int> indices = findZeroIndex(map);
    int random_idx = rand() % indices.size();

    int rand_x = indices[random_idx] % map[0].size();
    int rand_y = (int)(indices[random_idx] / map[0].size());

    return std::make_tuple(map_start_pos_x + (block_size) * static_cast<float>(rand_x), map_start_pos_y+ (block_size) * static_cast<float>(rand_y));
}

const std::tuple<uint8_t, uint8_t> real2Index(Pos pos, const float block_size, const float map_start_pos_x, const float map_start_pos_y){
    /**
     * @brief convert Real Pos to Map Index
    */

    float real_x = pos.x;
    float real_y = pos.y;
    
    real_x -= map_start_pos_x;
    real_y -= map_start_pos_y;

    return std::make_tuple((int)(real_x / block_size), (int)(real_y / block_size));
}

const Pos idx2Real(uint8_t idx_x, uint8_t idx_y, const float block_size, const float map_start_pos_x, const float map_start_pos_y){
    /**
     * @brief convert Map Index to Real Pos (Center of Block)
    */

    float real_x = map_start_pos_x;
    float real_y = map_start_pos_y;
 
    real_x += static_cast<float>(idx_x) * block_size + block_size / 2;
    real_y += static_cast<float>(idx_y) * block_size; + block_size / 2;

    return { real_x, real_y };
}

#endif // __UTILS_H
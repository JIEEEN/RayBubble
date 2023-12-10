#include <utils.h>

const std::tuple<float, float> getMapStartTuple(Config& cfg){
    float center_width = cfg.screen_width/2;
    float center_height = cfg.screen_height/2;

    float half_block_size = cfg.map_block_size/2;
    float half_map_size_x = 7*cfg.map_block_size + half_block_size;
    float half_map_size_y = 6*cfg.map_block_size + half_block_size;

    return std::make_tuple(center_width - half_map_size_x, center_height - half_map_size_y);
}

const std::tuple<float, float> randomizePlayerPos(map_t& map, Config& cfg){
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

    return std::make_tuple(cfg.map_start_pos_x + (cfg.map_block_size) * static_cast<float>(rand_x), cfg.map_start_pos_y+ (cfg.map_block_size) * static_cast<float>(rand_y));
}

const std::tuple<uint8_t, uint8_t> real2Index(Pos pos, Config& cfg){
    /**
     * @brief convert Real Pos to Map Index
     * @param block_size : Map Block Size
    */

    float real_x = pos.x;
    float real_y = pos.y;
    
    real_x -= cfg.map_start_pos_x + cfg.player_size / 2;
    real_y -= cfg.map_start_pos_y + cfg.player_size / 2;

    return std::make_tuple((uint8_t)(real_x / cfg.map_block_size), (uint8_t)(real_y / cfg.map_block_size));
}

const Pos idx2Real(uint8_t idx_x, uint8_t idx_y, Config cfg){
    /**
     * @brief convert Map Index to Real Pos (Center of Block)
    */

    float real_x = cfg.map_start_pos_x;
    float real_y = cfg.map_start_pos_y;
 
    real_x += static_cast<float>(idx_x) * cfg.map_block_size + (cfg.map_block_size / 2);
    real_y += static_cast<float>(idx_y) * cfg.map_block_size + (cfg.map_block_size / 2);

    return { real_x, real_y };
}
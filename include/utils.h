#ifndef __UTILS_H_
#define __UTILS_H_

#include <common.h>
#include <type.h>

const std::tuple<float, float> getMapStartTuple(Config& cfg);
const std::tuple<float, float> randomizePlayerPos(map_t& map, Config& cfg);
const std::tuple<uint8_t, uint8_t> real2Index(Pos pos, Config& cfg);
const Pos idx2Real(uint8_t idx_x, uint8_t idx_y, Config& cfg);

#endif // __UTILS_H_


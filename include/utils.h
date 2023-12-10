#ifndef __UTILS_H_
#define __UTILS_H_

#include <common.h>
#include <Player.h>
#include <type.h>
#include <namespace.h>

using namespace RB_NAMESPACE;

const std::tuple<float, float> getMapStartTuple(Config &cfg);
const std::tuple<float, float> randomizePlayerPos(map_t &map, Config &cfg);
const mapidx_t realCenter2Index(Pos pos, Config &cfg);
const Pos getBoxPoint(const uint8_t, Player&);
const Pos index2Real(uint8_t, uint8_t, Config&);
const mapidx_t realPoint2Index(Pos, Config&);

#endif // __UTILS_H_

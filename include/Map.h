#ifndef __MAP_H_
#define __MAP_H_

#include <common.h>
#include <namespace.h>
#include <type.h>

RB_NAMESPACE_BEGIN

class Map{
    private:
        map_t map_template;

        map_t map1;
        map_t map2;
    public:
        Map(): map_template(15, std::vector<uint8_t>(13, 0)){};
        ~Map(){};
        void mapInit();
        map_t& getMap(const int& map_num) ;
};

RB_NAMESPACE_END

#endif // __MAP_H_
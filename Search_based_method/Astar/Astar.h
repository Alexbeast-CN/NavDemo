//
// Created by tim on 22-11-16.
//

#ifndef NAVDEMO_ASTAR_H
#define NAVDEMO_ASTAR_H

#include "Util/util.h"
#include "map.h"

using CellPath std::vector<CellIndex>;

typedef enum _AStarType
{
    EUCLIDEAN,
    MANHATTAN,
} AStarType;

class Astar{
public:
    Astar(Map &map, AStarType type) : map_(map), type_(type) {};
    CellPath get_path(CellIndex start, CellIndex goal);

private:
    Map::Map         map_;
    AStarType   type_;

private:
    inline float heuristic(CellIndex a, CellIndex b) {
        if (type_ == EUCLIDEAN) {
            return L2_distance(a, b);
        } else if (type_ == MANHATTAN) {
            return L1_distance(a, b);
        }
    }



};

};

#endif //NAVDEMO_ASTAR_H

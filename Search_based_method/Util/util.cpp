//
// Created by tim on 22-11-16.
//
#include "util.h"

std::vector<CellIndex> get_neighbours4(CellIndex a){
    std::vector<CellIndex> neighbours;
    std::vector<int> list{-1, 1};
    for (int i : list){
        for (int j : list){
            CellIndex neighbour;
            neighbour.x = a.x + i;
            neighbour.y = a.y + j;
            neighbours.push_back(neighbour);
        }
    }
    return neighbours;
}

std::vector<CellIndex> get_neighbours8(CellIndex a){
    std::vector<CellIndex> neighbours;
    std::vector<int> list{-1, 0, 1};
    for (int i : list){
        for (int j : list){
            if (i == 0 && j == 0)
                continue;

            CellIndex neighbour;
            neighbour.x = a.x + i;
            neighbour.y = a.y + j;
            neighbours.push_back(neighbour);
        }
    }
    return neighbours;
}
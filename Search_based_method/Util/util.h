//
// Created by tim on 22-11-16.
//

#ifndef NAVDEMO_UTIL_H
#define NAVDEMO_UTIL_H

#include <vector>
#include <iostream>
#include <cmath>

struct CellIndex{
  int x;
  int y;
};

float L1_distance(CellIndex a, CellIndex b){
  return abs(a.x - b.x) + abs(a.y - b.y);
}

float L2_distance(CellIndex a, CellIndex b){
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

std::vector<CellIndex> get_neighbours4(CellIndex a);
std::vector<CellIndex> get_neighbours8(CellIndex a);



#endif //NAVDEMO_UTIL_H

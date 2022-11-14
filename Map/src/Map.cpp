//
// Created by tim on 22-11-14.
//

#include <iostream>
#include <vector>
#include <string>

#include "Map.h"


void Map::loadMap(const char *filename) {

}

void Map::set_block_obs(int x, int y, int width, int height) {
    if (!is_block_valid(x, y, width, height)){
        std::cout << "Invalid block!" << std::endl;
        return;
    }
    for (int i = x; i < x + width; ++i) {
        for (int j = y; j < y + height; ++j) {
            map_(i, j) = int(OBSTACLE);
        }
    }
}

void Map::set_line_obs(int x1, int y1, int x2, int y2) {
    if (!is_block_valid(x1, y1, x2, y2)){
        std::cout << "Invalid block!" << std::endl;
        return;
    }
    int x_max = std::max(x1, x2);
    int x_min = std::min(x1, x2);
    float k = (y2 - y1) / (x2 - x1);
    float b = y1 - k * x1;
    for (int i = x_min; i < x_max; ++i) {
        int j = k * i + b;
        map_(i, j) = int(OBSTACLE);
    }
}

bool Map::is_block_valid(int x, int y, int width, int height) {
    if (x < 0 || x >= col_ || y < 0 || y >= row_)
         return false;
    if (x + width > col_ || y + height > row_)
        return false;
    if (width <= 0 || height <= 0)
        return false;

    return true;
}

bool Map::is_line_valid(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= col_ || y1 < 0 || y1 >= row_)
        return false;
    if (x2 < 0 || x2 >= col_ || y2 < 0 || y2 >= row_)
        return false;

    return true;
}





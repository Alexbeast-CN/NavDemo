//
// Created by tim 2022/11/13
//

#ifndef NAVDEMO_MAP_H
#define NAVDEMO_MAP_H

#include "Eigen/Dense"

/**************************************************
 * Map class features:
 * - Have a default map.
 * - Load a map from a file.
 * - Save a map to a file.
 * - Build a map with code.
 * - generate a random map.
****************************************************/

typedef Eigen::MatrixXi matrix;

struct Cell_Indx{
    int x;
    int y;
};

enum _MAP_CONFIG
{
    OBSTACLE    = 0,
    FREE        = 255,
    START       = 100,
    GOAL        = 200,
};

class Map {
public:
    // Generate a blank map.
    Map(int row, int col)
    : row_(row)
    , col_(col)
    , start_(Cell_Indx{0, 0})
    , goal_(Cell_Indx{row - 1, col - 1})
    , map_(matrix::Ones(row, col) * int(FREE))
    {
        map_(start_.x, start_.y) = int(START);
        map_(goal_.x, goal_.y)   = int(GOAL);
    };

    // Generate default map.
    Map()
    : row_(60)
    , col_(80)
    , start_(Cell_Indx{1, 1})
    , goal_(Cell_Indx{row_-1, col_-1})
    , map_(matrix::Ones(row_, col_) * int(FREE))

    {
        set_block_obs(5, 0, 10, 10);
        map_(start_.x, start_.y) = int(START);
        map_(goal_.x, goal_.y)   = int(GOAL);
    };

    // Generate a random map.
    void random_map(int num_obs);

    virtual         ~Map(){};
    inline int      getRow() const { return row_; }
    inline int      getCol() const { return col_; }
    inline int      getValue(int x, int y) const { return map_(x, y); }
    inline matrix * getMapPtr() { return &map_; }

    void loadMap(const char* filename);

    // (x, y) is the top left corner of the block.
    void set_block_obs(int x, int y, int width, int height);
    bool is_block_valid(int x, int y, int width, int height);

    void set_line_obs(int x1, int y1, int x2, int y2);
    bool is_line_valid(int x1, int y1, int x2, int y2);

protected:
    int             row_;
    int             col_;
    matrix          map_;
    Cell_Indx       start_;
    Cell_Indx       goal_;

};

#endif //NAVDEMO_MAP_H

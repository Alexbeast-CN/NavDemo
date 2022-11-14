//
// Created by Daoming Chen 2022/11/13
//
#include "Eigen/Dense"

typedef Eigen::MatrixX2i matrix;

enum _MAP_CONFIG
{
    OBSTACLE    = 0,
    FREE        = 255,
}MAP_CONFIG;

class Map {
public:
    Map();
    virtual  ~Map();

    Map(int row, int col) : row_(row), col_(col) {
        setMap();
    };

    Map(int row, int col, bool is_random) : row_(row), col_(col) {
        setMap(row, col, is_random);
    };


    inline void setMap(int row, int col){
        map_ = matrix::Ones(row, col) * int(FREE);
    }

    inline void setMap(int row, int col, bool is_random){
        map_ = matrix::Ones(row, col) * int(FREE);
    }

    int getRow() { return row_; }
    int getCol() { return col_; }

    void pad(int pad_size);

protected:
    int     row_;
    int     col_;
    float   resolution_;
    matrix  map_;

    inline void setMap(){
        map_ = matrix::Ones(row_, col_) * int(FREE);
    }
};
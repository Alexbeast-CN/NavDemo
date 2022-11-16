//
// Created by tim on 22-11-14.
//

#include "Map.h"
#include "Plot.h"

int main(){
    Map map(40, 50);
    map.random_map(20*30);
    Plot plot(map);
    plot.display_static_map();
    return 0;
}
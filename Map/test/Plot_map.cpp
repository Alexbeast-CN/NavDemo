//
// Created by tim on 22-11-14.
//

#include "Map.h"
#include "Plot.h"

int main(){
    Map map(100, 100);
    Plot plot(map);
    plot.display_static_map();
    return 0;
}
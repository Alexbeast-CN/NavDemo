//
// Created by tim on 22-11-14.
//
#include "Plot.h"

void Plot::display_static_map() {
    cv::namedWindow("Map", cv::WINDOW_AUTOSIZE);
    cv::imshow("Map", img_);
    cv::waitKey(0);
}


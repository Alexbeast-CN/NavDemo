//
// Created by tim on 22-11-14.
//

#ifndef NAVDEMO_PLOT_H
#define NAVDEMO_PLOT_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Map.h"

/****************************************
 * class Plot
 * - Plot a map with opencv.
 * - animation the path generation process.
 ****************************************/

// OpenCV colors
namespace colors{
    #define RED         cv::Vec3b(0, 0, 255)
    #define GREEN       cv::Vec3b(0, 255, 0)
    #define BLUE        cv::Vec3b(255, 0, 0)
    #define WHITE       cv::Vec3b(255, 255, 255)
    #define YELLOW      cv::Vec3b(0, 255, 255)
    #define BLACK       cv::Vec3b(0, 0, 0)
    #define GREY        cv::Vec3b(128, 128, 128)
    #define LIGHTGREY   cv::Vec3b(200, 200, 200)
    #define LIMEGREEN   cv::Vec3b(50, 205, 50)
    #define FIREBRICK   cv::Vec3b(34, 34, 178)
    #define ROYALBLUE   cv::Vec3b(255, 105, 65)
};
using namespace colors;


class Plot {
private:
    Map     map_;
    cv::Mat img_;

public:
    Plot(Map& map)
    : map_(map)
    , img_(cv::Mat::zeros(map.getRow(), map.getCol(), CV_8UC3))
    {
        for (int i = 0; i < map.getRow(); ++i) {
            for (int j = 0; j < map.getCol(); ++j) {
                if (map.getValue(i, j) == int(OBSTACLE))
                    img_.at<cv::Vec3b>(i, j) = BLACK;
                else if (map.getValue(i, j) == int(START))
                    img_.at<cv::Vec3b>(i, j) = ROYALBLUE;
                else if (map.getValue(i, j) == int(GOAL))
                    img_.at<cv::Vec3b>(i, j) = RED;
                else
                    img_.at<cv::Vec3b>(i, j) = LIGHTGREY;
            }
        }
    };

    void display_static_map();
    virtual ~Plot()= default;


private:
    void padding(int padding_size);

};


#endif //NAVDEMO_PLOT_H

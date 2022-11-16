//
// Created by tim on 22-11-14.
//
#include "Plot.h"

void Plot::display_static_map() {
//    cv::namedWindow("Map", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Map", cv::WINDOW_KEEPRATIO);
    padding(1);
    //    resize the window
    cv::imshow("Map", img_);
    cv::waitKey(0);
}

void Plot::padding(int padding_size = 1) {
    cv::Mat padded_img = cv::Mat::zeros(img_.rows + 2 * padding_size, img_.cols + 2 * padding_size, CV_8UC3);
    for (int i = 0; i < img_.rows; ++i) {
        for (int j = 0; j < img_.cols; ++j) {
            padded_img.at<cv::Vec3b>(i + padding_size, j + padding_size) = img_.at<cv::Vec3b>(i, j);
        }
    }
    img_ = padded_img;
}


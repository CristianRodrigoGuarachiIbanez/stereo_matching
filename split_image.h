//
// Created by cristian on 13.10.21.
//
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using cv::Mat;
using std::vector;
using std::endl;
using std::cout;

#ifndef STEREO_MATCHING_SPLIT_IMAGE_H
#define STEREO_MATCHING_SPLIT_IMAGE_H


class split_image {
    Mat image;
    int BWidth, BHeight, ImgWidth, ImgHeight;
    vector<Mat> blocksVector;
public:
    split_image(Mat& img, int blockWidth, int blockHeight) {

        this->image = img;
        if (!image.data || image.empty()){
            cout << "Image Error: Cannot load image to divide." << endl;
            //return EXIT_FAILURE;
        }
        this->ImgWidth= image.cols;
        this->ImgHeight=image.rows;
        cout<<ImgHeight<< " "<<ImgWidth<<endl;
        this->BWidth = blockWidth;
        this->BHeight = blockHeight;

    }
    int computeBlockHeight(int y0);
    int computeBlockWidth(int x0);
    void setBlocks(int x0, int y0, int bwSize, int bhSize);
    vector<Mat> getBlocks();
    int divideImage();
};



#endif //STEREO_MATCHING_SPLIT_IMAGE_H

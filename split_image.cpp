//
// Created by cristian on 13.10.21.
//

#include "split_image.h"
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
using std::vector;
using cv::Mat;
int split_image::computeBlockHeight(int y0) {
    return ((y0 + BHeight) > ImgHeight) * (BHeight - (y0 + BHeight - ImgHeight)) + ((y0 + BHeight) <= ImgHeight) * BHeight;
}
int split_image::computeBlockWidth(int x0) {
    return ((x0 + BWidth) > ImgWidth) * (BWidth - (x0 + BWidth - ImgWidth)) + ((x0 + BWidth) <= ImgWidth) * BWidth;
}
void split_image::setBlocks(int x0, int y0, int bwSize, int bhSize){
    this->blocksVector.push_back(image(cv::Rect(x0, y0, bwSize, bhSize)).clone());
}
vector<Mat> split_image::getBlocks(){
    return blocksVector;
}
int split_image::divideImage() {
    int bwSize, bhSize;
    int y0 = 0;
    while (y0 < ImgHeight){
        // compute the block height
        bhSize = split_image::computeBlockHeight(y0);

        int x0 = 0;
        while (x0 < ImgWidth){
            // compute the block height
            bwSize = split_image::computeBlockWidth(x0);

            // crop block
            split_image::setBlocks(x0, y0, bwSize, bhSize);

            // update x-coordinate
            x0 = x0 + BWidth;
        }

        // update y-coordinate
        y0 = y0 + BHeight;
    }
    return EXIT_SUCCESS;

}

int main(){
    // init vars
    const int blockw = 128;
    const int blockh = 128;


    // read png image
    Mat image = cv::imread("im1.png", cv::IMREAD_UNCHANGED);
    cv::imshow("Display window", image);

    // divide image into multiple blocks
    split_image splitImage = split_image(image, blockw, blockh);
    int divideStatus = splitImage.divideImage();
    std::vector<cv::Mat> blocks = splitImage.getBlocks();
    // debug: save blocks
    boost::filesystem::create_directories("./blocksFolder");
    for (int j = 0; j < blocks.size(); j++)
    {
        std::string blockId = std::to_string(j);
        std::string blockImgName = "./blocksFolder/block#" + blockId + ".png";
        imwrite(blockImgName, blocks[j]);
    }

    return 0;
}
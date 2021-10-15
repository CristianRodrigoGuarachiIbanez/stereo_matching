//
// Created by cristian on 12.10.21.
//

#include "ssd_stereo.h"



int main(int argc, char** argv)
{
    cv::CommandLineParser parser(argc, argv, "{left||}{right||}{max-disparity|0|}{window_size|0|}{tranwin_size|0|}{output||}{parallel||}{cost||}{windows||}");
    //string leftname = parser.get<std::string>("left");
    //string rightname = parser.get<std::string>("right");
    //string outname = parser.get<std::string>("output");
    string parallel = parser.get<std::string>("parallel");
    //string windows = parser.get<std::string>("windows");
    string cost = parser.get<std::string>("cost");
    int max_disparity = parser.get<int>("max-disparity");
    //int window_size = parser.get<int>("window_size");
    //int tranwin_size = parser.get<int>("tranwin_size");

    string leftname = "./im1.png";
    string rightname = "./im2.png";
    string outname = "./output.png";
    int window_size = 7;
    int tranwin_size=7;
    Mat dis;
    Mat left = imread(leftname, 0); //read images into grayscale
    Mat right = imread(rightname, 0);
    if(!left.empty()){
        std::cout<<"left img is not empty"<<std::endl;
        //imshow("left", left);
        //waitKey(0);
    }
    int64 t2 = getTickCount();
    if (parallel == "no") {
        Stereo s(window_size, max_disparity, tranwin_size, cost, false);
        dis = s.stereo_match(left, right);
    }
    else {
        Stereo s(window_size, max_disparity, tranwin_size, cost, true);
        dis = s.stereo_match(left, right);
    }

    std::cout<<" output name:" <<outname<<std::endl;
    std::cout<<" left name:" <<leftname<<std::endl;
    t2 = getTickCount() - t2;
    printf("census Time elapsed: %fms\n", t2 * 1000 / getTickFrequency());
    if(!dis.empty()){
        //cv::imshow("Display Image",dis);
        std::cout<<"image is not empty:"<<std::endl;
    }
    waitKey(0);
    cv::imwrite(outname, dis);

    //system("pause");
    return 0;
}

#include <iostream>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/core/affine.hpp>
#include <opencv2/stereo.hpp>

int main(int argc, const    char * argv[]) {
    std::cout << CV_VERSION << std::endl;
    cv::Mat left = cv::imread("im1.png",0);
    cv::Mat right = cv::imread("im2.png",0);
    cv::Mat disparity_out;

    cv::Ptr< cv::StereoBM > match = cv::StereoBM::create();
    match->compute(left, right, disparity_out);
    imshow("test",disparity_out);
    cv::imwrite("test.png", disparity_out);

    return 0;
}
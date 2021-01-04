#include "opencv2/imgcodecs.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath> 


using namespace cv;
using namespace std;
class Stereo {
private:
	int win_size_, max_disparity_;
public:
	
	Stereo(int window_size, int max_dis) {
		win_size_ = window_size;  // block size 
		max_disparity_ = max_dis;
	}

	Mat stereo_match(Mat left, Mat right);
};
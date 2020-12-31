#include "opencv2/imgcodecs.hpp"
#include <stdio.h>
#include <iostream>


using namespace cv;
using namespace std;
class Stereo {
private:
	int win_size_, max_disparity_, tran_win_size_;
public:
	
	Stereo(int window_size, int max_dis, int tran_size) {
		win_size_ = window_size;  // block size 
		max_disparity_ = max_dis;
		tran_win_size_ = tran_size; // matching cost windows size
	}

	Mat transform(Mat image, int tran_size);
	Mat census_transform(Mat image, int tran_size);
	Mat stereo_match(Mat left, Mat right);
	Mat stereo_match_parallel(Mat left, Mat right);	
};
#include "ssd_stereo.h"

Mat Stereo::transform(Mat image, int windowsize) {
	int h = image.rows;
	int w = image.cols;
	Mat imgDisparity8U = Mat(image.rows, image.cols, CV_8U);
	int window_half = windowsize / 2;

	for (int y = window_half; y < h - window_half; ++y) {
		for (int x = window_half; x < w - window_half; ++x) {
			int ssd = 0;

			for (int v = -window_half; v < window_half + 1; ++v) {
				for (int u = -window_half; u < window_half + 1; ++u) {

					if (image.at<uchar>(y + v, x + u) > image.at<uchar>(y, x)) ++ssd;
				}

			}

			imgDisparity8U.at<uchar>(y, x) = ssd;

		}
	}
	return imgDisparity8U;
}


Mat Stereo::stereo_match(Mat left, Mat right) {
	int h = left.rows;
	int w = left.cols;
	Mat imgDisparity8U = Mat(left.rows, left.cols, CV_8U);
	int window_half = win_size_ / 2;
	int adjust = 255 / max_disparity_;

	left = Stereo::transform(left, tran_win_size_);
	right = Stereo::transform(right, tran_win_size_);

	for (int y = window_half; y < h - window_half; ++y) {
		uchar *imgDisparity_y = imgDisparity8U.ptr(y);
		for (int x = window_half; x < w - window_half; ++x) {
			int prev_ssd = INT_MAX;
			int best_dis = 0;
			for (int off = 0; off < max_disparity_; ++off) {
				int ssd = 0;
				int ssd_tmp = 0;
				for (int v = -window_half; v < window_half; ++v) {

					for (int u = -window_half; u < window_half; ++u) {

						ssd_tmp = left.at<uchar>(y + v, x + u) - right.at<uchar>(y + v, x + u - off);
						ssd += ssd_tmp * ssd_tmp;
					}

				}
				if (ssd < prev_ssd) {
					prev_ssd = ssd;
					best_dis = off;
				}


			}

			imgDisparity_y[x] = best_dis * adjust;
		}
	}
	
	//imwrite("dis.png", imgDisparity8U);
	return imgDisparity8U;
}

int main(int argc, char** argv)
{
	cv::CommandLineParser parser(argc, argv,
		"{left||}{right||}{max-disparity|0|}{window_size|0|}{tranwin_size|0|}{output||}");
	string leftname = parser.get<std::string>("left");
	string rightname = parser.get<std::string>("right");
	string outname = parser.get<std::string>("output");
	int max_disparity = parser.get<int>("max-disparity");
	int window_size = parser.get<int>("window_size");
	int tranwin_size = parser.get<int>("tranwin_size");

	Mat dis;
	Mat left = imread(leftname, 0); //read images into grayscale
	Mat right = imread(rightname, 0);
	int64 t2 = getTickCount();
	Stereo s(window_size, max_disparity, tranwin_size);
	dis = s.stereo_match(left, right);

	t2 = getTickCount() - t2;
	printf("census Time elapsed: %fms\n", t2 * 1000 / getTickFrequency());
	cv::imwrite(outname, dis);

	//system("pause");
	return 0;
}


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define WINDOW_NAME "trackbar test"

const int alpha_value_max = 100;
int alpha_value_slider;
double alpha_value_percent;
double beta_value_percent;
Mat img1, img2, img;

void trackbar2Img(int, void *)
{
    alpha_value_percent = double(alpha_value_slider) / alpha_value_max;
    beta_value_percent = (1.0 - alpha_value_percent);
    addWeighted(img1, alpha_value_percent, img2, beta_value_percent, 0, img);
    imshow(WINDOW_NAME, img);
}

int main()
{
    img1 = imread("D:/DailyTasks/C++Opencv/sources/001.jpg");
    img2 = imread("D:/DailyTasks/C++Opencv/sources/002.jpg");
    if (!img1.data)
    {
        cout << "Error at img1";
        return -1;
    }
    if (!img2.data)
    {
        cout << "Error at img2";
        return -1;
    }

    // imshow("test1",img1);
    // imshow("test2",img2);
    alpha_value_slider = 50;
    namedWindow(WINDOW_NAME);
    char TrackbarName[50];
    sprintf(TrackbarName, "Í¸Ã÷¶È%d", alpha_value_max);
    createTrackbar(TrackbarName, WINDOW_NAME, &alpha_value_slider, alpha_value_max, trackbar2Img);
    trackbar2Img(alpha_value_slider, 0);
    waitKey(0);
    return 0;
}

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat src = imread("D:/DailyTasks/C++Opencv/sources/001.jpg");
    if (src.empty())
    {
        printf("....\n");
        return -1;
    }
    // namedWindow("���봰��", WINDOW_FREERATIO);
    imshow("���봰��", src);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

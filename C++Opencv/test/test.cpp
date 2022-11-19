
// #include <opencv2/opencv.hpp>
// #include <iostream>
// #include <windows.h>

// using namespace cv;
// using namespace std;

// int main()
// {
//     VideoCapture cap(0);
//     Sleep(3000);
//     Mat img;

//     while (1)
//     {
//         cap >> img;
//         if (img.empty())
//             break;
//         namedWindow("img", WINDOW_NORMAL);
//         imshow("img", img);
//         if (27 == waitKey(20))
//             break;
//     }

//     return 0;
// }


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat src = imread("D:/test.jpg");
    if (src.empty())
    {
        printf("....\n");
        return -1;
    }
    namedWindow("输入窗口", WINDOW_FREERATIO);
    imshow("输入窗口", src);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

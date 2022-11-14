
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap(0);
    Mat img;

    while (1)
    {
        cap >> img;
        if (img.empty())
            break;
        namedWindow("img", WINDOW_NORMAL);
        imshow("img", img);
        if (27 == waitKey(20))
            break;
    }
    int a;
    cin >> a;
    system("pause");
    return 0;
}

// int main()
// {
//     cout << "1" ;
//     system("pause");
// }
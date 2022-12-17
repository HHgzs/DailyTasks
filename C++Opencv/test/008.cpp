#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main()
{

    Mat image = imread("D:/DailyTasks/C++Opencv/sources/001.jpg");
    Mat dst;
    
    int colormap[] = {
        COLORMAP_AUTUMN,
        COLORMAP_BONE,
        COLORMAP_JET,
        COLORMAP_WINTER,
        COLORMAP_RAINBOW,
        COLORMAP_OCEAN,
        COLORMAP_SUMMER,
        COLORMAP_SPRING,
        COLORMAP_COOL,
        COLORMAP_HSV,
        COLORMAP_PINK,
        COLORMAP_HOT,
        COLORMAP_PARULA,
        COLORMAP_MAGMA,
        COLORMAP_INFERNO,
        COLORMAP_PLASMA,
        COLORMAP_VIRIDIS,
        COLORMAP_CIVIDIS,
        COLORMAP_TWILIGHT,
        COLORMAP_TWILIGHT_SHIFTED,
        COLORMAP_TURBO,
        COLORMAP_DEEPGREEN};
    int index = 0;

    while (true)
    {
        int c = waitKey(500);
        if (c == 27)
        { // key:esc
            break;
        }
        applyColorMap(image, dst, colormap[index % 21]);
        index++;
        imshow("ÑÕÉ«·ç¸ñ", dst);
    }
}
#include "pch.h"
#include "quickdemo.cpp"
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    
    QuickDemo qd;
    qd.mat_creation_Demo();

    waitKey(0);
    destroyAllWindows();
    return 0;
}

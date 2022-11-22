#include "pch.h"

//002
void QuickDemo::colorSpace_Demo(Mat &image) {
	Mat hsv,gray;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("1", hsv);
	imshow("2", gray);
	imwrite("sources/test/hsv.jpg", hsv);
	imwrite("sources/test/gray.jpg", gray);
} 



//003
void QuickDemo::mat_creation_Demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	// new �հ�ͼ��
	Mat m3 = Mat::ones(Size(32, 32), CV_8UC3);     //��λ�޷��ŵ�ͨ��
	m3 = Scalar(22,22,99);                         //����ͬ��ͨ����ֵ
	std::cout << m3.cols<<"  " << m3.rows<<"  "<<m3.channels() << std::endl;
	std::cout << m3 <<std::endl;
	

	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(0, 255, 255);

	imshow("dfa", m4);
    //imshow("clone", m4);
}

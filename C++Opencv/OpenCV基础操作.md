# OpenCV基础操作



## 1、图像的读取与显示

**所使用的API接口：**

- imread(path)，其中path路径中不要出现中文，否则会报错。
- imshow()
- nameWindonw()

**代码演示：**

```cpp
#include<pch.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src = imread("D:/opencv/test.jpg");
	if (src.empty()) {
		printf("....\n");
		return -1;
	}
	//namedWindow("输入窗口", WINDOW_FREERATIO);
	imshow("输入窗口", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

```



## 2、图像色彩空间转换

**所使用的API接口：**

- cvtColor()

**代码演示：**

首先在pch.h的头文件中创建QuickDemo类，再定义一个类方法colorSpace_Demo()：

```cpp
#include<opencv2/opencv.hpp>
using namespace cv;

class QuickDemo {
public:
	void colorSpace_Demo(Mat &image);
};
```

然后在quickdemo.cpp文件中重写colorSpace_Demo()方法：

```cpp
void QuickDemo::colorSpace_Demo(Mat &image) {
	Mat hsv,gray;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("1", hsv);
	imshow("2", gray);
	imwrite("hsv.jpg", hsv);
	imwrite("gray.jpg", gray);
} 
```

然后程序入口处调用即可：

```cpp
#include<pch.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv) {
	Mat src = imread("D:/opencv/test.jpg");
	if (src.empty()) {
		printf("....\n");
		return -1;
	}
	//namedWindow("输入窗口", WINDOW_FREERATIO);
	imshow("输入窗口", src);

	QuickDemo qd;
	qd.colorSpace_Demo(src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

```



## 3、图像对象的创建与赋值

**所使用的API接口**：

Scalar()

**代码演示：**

使用方法与上例2的演示一样

```cpp
void QuickDemo::mat_creation_Demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	// new 空白图像
	Mat m3 = Mat::ones(Size(32, 32), CV_8UC3);//八位无符号单通道
	m3 = Scalar(22,22,99);//给不同的通道赋值
	std::cout << m3.cols<<"  " << m3.rows<<"  "<<m3.channels() << std::endl;
	std::cout << m3 <<std::endl;
	

	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(0, 255, 255);

	imshow("dfa", m3);
}

```







### Scalar()

**一、Scalar(a)  灰度值**

1、Scalar(0)  黑色

```cpp
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
void main()
{
	Mat rawImg(500, 300, CV_8U, Scalar(0));	
	imshow("Raw Image", rawImg);
	waitKey(0);
	destroyAllWindows();
}
```

![img](https://img-blog.csdnimg.cn/20210907164806161.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAd2FuZ3BhaWxpdWxhbnFpOA==,size_8,color_FFFFFF,t_70,g_se,x_16)

 2、Scalar(255)  白色

3、Scalar(100)  灰色



**二、Scalar(B,G.R)   BGR3通道颜色**

1、Scalar(255,0,0)  蓝色

> Mat rawImg(300, 300, CV_8UC3, Scalar(255,0,0));    
>
> // Scalar(255,0,0)  效果等同于 { 255,0,0 }  

![img](https://img-blog.csdnimg.cn/202109071653369.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAd2FuZ3BhaWxpdWxhbnFpOA==,size_8,color_FFFFFF,t_70,g_se,x_16)



**三、Scalar(B,G.R,C)   Blue,Green,Red,Channels**

**四、Scalar(H,S.V)** 

 hue色调，saturation饱和度，value亮度

一般用于inRange函数

> Scalar lower = Scalar(hmin, smin, vmin);    // 效果等同于 Scalar lower = { hmin, smin, vmin}
> Scalar upper = Scalar(hmax, smax,vmax);
> inRange(imgHSV, lower, upper, mask);



**五、Scalar 初始化的格式**

- Scalar(hmin, smin, vmin);
- Scalar lower = { hmin, smin, vmin}；
- Scalar lower = (hmin, smin, vmin)：错误







## 4、像素的读写操作

**所使用的API接口：**

- int pv = image.at(row, col); //获取像素值

**代码演示：**

```cpp
void QuickDemo::pixel_visit_Demo(Mat &image) {
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	/*
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (dims == 1) {// 单通道
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dims == 3) {// 三通道
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col) = 255 - bgr[0];
				image.at<Vec3b>(row, col) = 255 - bgr[1];
				image.at<Vec3b>(row, col) = 255 - bgr[2];
			}
		}
	}
	*/

	// 通过指针方式读取每个像素
	for (int row = 0; row < h; row++) {
		uchar* current_row = image.ptr<uchar>(row);
		for (int col = 0; col < w; col++) {
			if (dims == 1) {// 单通道
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dims == 3) {// 三通道
				Vec3b bgr = image.at<Vec3b>(row, col);
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("像素演示", image);
	waitKey(0);
}

```



## 5、像素的算术操作

**所使用的API接口：**

- add(image, m, dst);
- subtract(image, m, dst);
- multiply(image, m, dst);
- divide(image, m, dst);

**代码演示：**

```cpp
void QuickDemo::operators_demo(Mat &image) {
	Mat dst = Mat::zeros(image.size(),image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(20, 2, 2);
	//dst = image - Scalar(50, 50, 50);		//加减可以
	
	/*
	int w = image.cols;
	int h = image.rows;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			Vec3b p1 = image.at<Vec3b>(row, col);
			Vec3b p2 = m.at<Vec3b>(row, col);
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	*/
	//add(image, m, dst);
	//subtract(image, m, dst);
	///multiply(image, m, dst);
	divide(image, m, dst);

	imshow("dst", dst);
}

123456789101112131415161718192021222324252627
```



## 6、滚动条调整图像亮度与对比度

**所使用的API接口：**

- addWeighted(）
- createTrackbar(）

**代码演示：**

```cpp
static void on_lightness(int lightness, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	addWeighted(image, 1.0, m, 0, lightness, dst);
	imshow("亮度与对比度调整", dst);
}

static void on_contrast(int lightness, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = lightness / 100.0;
	addWeighted(image, contrast, m, 0.0,0 , dst);
	imshow("亮度与对比度调整", dst);
}

void QuickDemo::tracking_bar_demo(Mat &image) {
	namedWindow("亮度与对比度调整", WINDOW_AUTOSIZE);
	int lightness = 50;
	int max_value = 100;
	int contrast_value = 100;
	createTrackbar("value_bar:", "亮度与对比度调整", &lightness, max_value, on_lightness,(void*)(&image));
	createTrackbar("contrast_bar:", "亮度与对比度调整", &contrast_value, 200, on_contrast, (void*)(&image));
	on_lightness(50, &image);
}

123456789101112131415161718192021222324252627
```



## 7、键盘响应

**所使用的API接口：**

- 略

**代码演示：**

```cpp
void QuickDemo::key_demo(Mat &image) {
	Mat dst = Mat::zeros(image.size(),image.type());
	while (true) {
		int c = waitKey(100);
		if (c == 27) {//key:esc
			break;
		}
		if (c == 49) {//key=1
			std::cout << "key #1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == 50) {//key=2
			std::cout << "key #2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		if (c == 51) {//key=3
			std::cout << "key #3" << std::endl;
			dst = Scalar(40, 20, 30);
			add(image, dst, dst);
		}
		imshow("键盘响应", dst);
	}
}
1234567891011121314151617181920212223
```



## 8、Opencv自带颜色表操作（滤镜）

**所使用的API接口：**

- applyColorMap()

**代码演示：**

```cpp
void QuickDemo::color_style_demo(Mat &image) {
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
  COLORMAP_DEEPGREEN
	};
	int index = 0;
	while (true) {
		int c = waitKey(500);
		if (c == 27) {//key:esc
			break;
		}
		applyColorMap(image, dst, colormap[index % 21]);
		index++;
		imshow("颜色风格", dst);
	}
}
12345678910111213141516171819202122232425262728293031323334353637
```



## 9、像素逻辑操作

**所使用的API接口：**

- bitwise_and(m1, m2, dst);
- bitwise_or(m1, m2, dst);
- bitwise_not(image, dst); // 另一种取反方式：Mat dst = ~image;
- bitwise_xor(m1, m2, dst);

**代码演示：**

```cpp
void QuickDemo::bitwise_demo(Mat &image) {
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0),-1,LINE_8,0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0,255, 255), -1,LINE_8,0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	//bitwise_and(m1, m2, dst);
	//bitwise_or(m1, m2, dst);
	//bitwise_not(image, dst); // 另一种取反方式：Mat dst = ~image;
	//bitwise_xor(m1, m2, dst);
	imshow("位操作", dst);
}
1234567891011121314
```



## 10、[通道](https://so.csdn.net/so/search?q=通道&spm=1001.2101.3001.7020)分离与合并

**所使用的API接口：**

- split()
- merge()

**代码演示：**

```cpp
void QuickDemo::split_merge_demo(Mat &image) {
	std::vector<Mat>mv;
	split(image, mv);
	imshow("b", mv[0]);
	imshow("g", mv[0]);
	imshow("r", mv[0]);
	
	Mat dst;
	mv[0] = 0;
	//mv[1] = 0;
	merge(mv, dst);
	imshow("dst", dst);

	int from_to[] = { 0,2,1,1,2,0 };
	mixChannels(&image,1, &dst,1, from_to,3);
	imshow("通道混合", dst);
}
1234567891011121314151617
```



## 11、颜色提取与转换

**所使用的API接口：**

- inRange()

**代码演示：**

```cpp
void QuickDemo::inrange_demo(Mat &image) {
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;
	inRange(hsv, Scalar(35,43,46),Scalar(77,255,255),mask);
	
	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);
	bitwise_not(mask, mask);
	image.copyTo(redback, mask);
	imshow("roi", redback);
}
123456789101112
```



## 12、像素值统计

**所使用的API接口：**

- minMaxLoc()
- meanStdDev()

**代码演示：**

```cpp
void QuickDemo::pixel_statistic_demo(Mat &image) {
	double minv, maxv;
	Point minloc, maxloc;
	//cvtColor(image, image,COLOR_BGR2GRAY);
	std::vector<Mat>mv;
	split(image, mv);
	for (int i = 0; i < image.channels(); i++) {
		minMaxLoc(mv[i], &minv, &maxv, &minloc, &maxloc, Mat());
		std::cout << "min value:" << minv << "  max value:" << maxv << std::endl;
	}
	Mat mean, stddev;
	meanStdDev(image, mean, stddev);
	std::cout << "mead:" << mean << "  stddev:" << stddev << std::endl;
}
1234567891011121314
```

# 13、几何图形绘制

## 所使用的API接口：

- rectangle()
- circle()
- line()
- ellipse()

## 代码演示：

```cpp
void QuickDemo::drawing_demo(Mat &image) {
	Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.width = 50;
	rect.height = 50;
	Mat bg = Mat::zeros(image.size(), image.type());
	Mat dst;
	rectangle(image,rect,Scalar(0, 0, 255), -1, 8, 0);
	circle(image, Point(50, 50), 45, Scalar(255, 0, 0), -1, 8, 0);
	line(image, Point(50, 50), Point(100, 100), Scalar(0, 255, 0), 2, 8, 0);
	RotatedRect rrt;
	rrt.center = Point(100, 100);
	rrt.size = Size(100, 50);
	rrt.angle = 0.0;
	ellipse(image, rrt, Scalar(255, 255, 0), 2, 8);
	addWeighted(image, 0.7, bg, 0.3, 0, dst);
	imshow("绘制演示", dst);
}
12345678910111213141516171819
```

# 14、随机数与随机颜色

## 所使用的API接口：

- RNG rng()

## 代码演示：

```cpp
void QuickDemo::random_drawing() {
	Mat bg = Mat::zeros(Size(600, 600), CV_8UC3);
	int w = bg.cols;
	int h = bg.rows;
	RNG rng(12345);
	while (true) {
		int c = waitKey(50);
		if (c == 27) {
			break;
		}
		int x1 = rng.uniform(0, w);
		int y1 = rng.uniform(0, h);
		int x2 = rng.uniform(0, w);
		int y2 = rng.uniform(0, h);
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		bg = Scalar(0, 0, 0);
		line(bg, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 2, 8, 0);
		imshow("随机绘制", bg);
	}
}
12345678910111213141516171819202122
```

# 15、多边形填充与绘制

## 所使用的API接口：

- fillPoly()
- polylines()
- drawContours()

## 代码演示：

```cpp
void QuickDemo::polyline_drawing_demo() {
	Mat bg = Mat::zeros(Size(512, 512), CV_8UC3);
	Point p1(100, 100);
	Point p2(350, 100);
	Point p3(400, 280);
	Point p4(320, 480);
	Point p5(80, 400);
	std::vector<Point> pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	//fillPoly(bg, pts, Scalar(255, 0, 0), 8, 0);
	//polylines(bg, pts, true, Scalar(0, 0, 255), 2, LINE_AA, 0);
	std::vector<std::vector<Point>> cnts;
	cnts.push_back(pts);
	drawContours(bg, cnts, -1,Scalar(0,255,0),2);
	imshow("多边形绘制", bg);
}
1234567891011121314151617181920
```

# 16、鼠标操作与响应

## 所使用的API接口：

- setMouseCallback()

## 代码演示：

```cpp
Point sp(-1, -1);
Point ep(-1, -1);
Mat temp;
static void on_drawing(int event,int x,int y,int flags,void *userdata) {
	Mat image = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {
		sp.x = x;
		sp.y = y;
		std::cout << "start point:" << sp <<std::endl;
	}
	else if (event == EVENT_LBUTTONUP) {
		ep.x = x;
		ep.y = y;
		int dx = ep.x - sp.x;
		int dy = ep.y - sp.y;
		if(dx >= 0 && dy > 0) {
			Rect box(sp.x, sp.y, dx, dy);
			temp.copyTo(image);
			imshow("截取ROI", image(box));
			rectangle(image, box, Scalar(0, 255, 0), 2, 8);
			imshow("鼠标绘制", image);
			sp.x = -1;
			sp.y = -1;
		}	
	}
	else if (event == EVENT_MOUSEMOVE) {
		if (sp.x > 0 && sp.y > 0) {
			ep.x = x;
			ep.y = y;
			int dx = ep.x - sp.x;
			int dy = ep.y - sp.y;
			if (dx >= 0 && dy > 0) {
				Rect box(sp.x, sp.y, dx, dy);
				temp.copyTo(image);
				rectangle(image, box, Scalar(0, 255, 0), 2, 8);
				imshow("鼠标绘制", image);
			}
		}
	}
}

void QuickDemo::mouse_drawing_demo(Mat &image) {
	namedWindow("鼠标绘制", WINDOW_AUTOSIZE);
	setMouseCallback("鼠标绘制", on_drawing,(void*)(&image));
	imshow("鼠标绘制", image);
	temp = image.clone();
}
1234567891011121314151617181920212223242526272829303132333435363738394041424344454647
```

# 17、像素类型转换与归一化

## 所使用的API接口：

- image.convertTo()
- normalize()

## 代码演示：

```cpp
void QuickDemo::norm_demo(Mat &image) {
	Mat dst;
	std::cout << image.type() << std::endl;
	image.convertTo(image, CV_32F);
	std::cout << image.type() << std::endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX);
	std::cout << dst.type() << std::endl;
	imshow("图像数据归一化", dst);
}
123456789
```

# 18、图像放缩与插值

## 所使用的API接口：

- resize()

## 代码演示：

```cpp
void QuickDemo::resize_demo(Mat &image) {
	Mat zoomin, zoomout;
	int h = image.cols;
	int w = image.rows;
	resize(image, zoomin, Size(w / 1.5, h / 1.5), 0, 0, INTER_LINEAR);
	resize(image, zoomout, Size(w * 1.2, h * 1.2), 0, 0, INTER_LINEAR);
	imshow("缩小", zoomin);
	imshow("放大", zoomout);
}
123456789
```

# 19、图像翻转

## 所使用的API接口：

- flip()

## 代码演示：

```cpp
void QuickDemo::flip_demo(Mat &image) {
	Mat dst;
	flip(image, dst, 1);// 0以x为轴镜像，1以y轴镜像，-1以x=y为轴镜像
	imshow("图像翻转", dst);
}
12345
```

# 20、图像旋转

## 所使用的API接口：

- getRotationMatrix2D()
- warpAffine()

## 代码演示：

```cpp
void QuickDemo::rotate_demo (Mat &image) {
	Mat M, dst;
	int w = image.cols;
	int h = image.rows;
	M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
	double cos = abs(M.at<double>(0, 0));
	double sin = abs(M.at<double>(0, 1));
	int nw = w * cos + h * sin;
	int nh = w * sin + h * cos;
	M.at<double>(0, 2) += (nw / 2 - w / 2);
	M.at<double>(1, 2) += (nh / 2 - h / 2);
	warpAffine(image, dst, M,Size(nw,nh),INTER_LINEAR,0,Scalar(0,255,0));
	imshow("旋转", dst);
}
1234567891011121314
```

# 21、视频文件读取、操作与保存

## 所使用的API接口：

- VideoCapture capture()

## 代码演示：

```cpp
void QuickDemo::video_demo(Mat &image) {
	VideoCapture capture("D:/opencv/test.mp4");
	Mat frame;
	int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);
	int frame_nums = capture.get(CAP_PROP_FRAME_COUNT);
	double frame_fps = capture.get(CAP_PROP_FPS);
	std::cout << "帧宽：" << frame_width << std::endl;
	std::cout << "帧高：" << frame_height << std::endl;
	std::cout << "帧数：" << frame_nums << std::endl;
	std::cout << "帧率：" << frame_fps << std::endl;
	VideoWriter writer("D:/opencv/test_flip.mp4",capture.get(CAP_PROP_FOURCC),frame_fps,Size(frame_width,frame_height),true);
	while (true) {
		capture.read(frame);
		flip(frame, frame, 1);
		writer.write(frame);
		if (frame.empty()) {
			break;
		}
		imshow("frame", frame);
		int c = waitKey(10);
		if (c == 27) {
			break;
		}
	}
	capture.release();
	writer.release();
}
12345678910111213141516171819202122232425262728
```

# 22、图像直方图

## 所使用的API接口：

- calcHist()

## 代码演示：

```cpp
void QuickDemo::showHistogram_demo(Mat &image) {
	// 三通道分离
	std::vector<Mat> bgr_plane;
	split(image, bgr_plane);
	// 定义参数变量
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float *ranges[1] = { hranges };
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	// 计算直方图
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
	// 显示直方图
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w/bins[0]);
	Mat histImage = Mat::zeros(Size(hist_w, hist_h), CV_8UC3);
	// 归一化直方图数据
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	// 绘制直方图曲线
	for (int i = 1; i < bins[0]; i++) {
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*i, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*i, hist_h - cvRound(g_hist.at<float>(i))), Scalar( 0,255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*i, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0,255), 2, 8, 0);
	}
	imshow("直方图", histImage);
}
123456789101112131415161718192021222324252627282930313233343536
```

# 23、二维直方图

## 所使用的API接口：

- 略

## 代码演示：

```cpp
void QuickDemo::histogram_2d_demo(Mat &image) {
	// 2D直方图
	Mat hsv, hs_hist;
	cvtColor(image, hsv, COLOR_RGB2HSV);
	int hbins = 30, sbins = 32;
	int hist_bins[] = { hbins,sbins };
	float hrange[] = { 0,180 };
	float srange[] = { 0,360 };
	const float *hs_ranges[] = { hrange,srange };
	int hs_channels[] = { 0,1 };
	calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
	double maxValue = 0.0;
	minMaxLoc(hs_hist, 0, &maxValue, 0, 0);
	int scale = 10;
	Mat hist_2d = Mat::zeros(Size(sbins*scale, sbins*scale), CV_8UC3);
	for (int h = 0; h < hbins; h++) {
		for (int s = 0; s < sbins; s++) {
			float binVal = hs_hist.at<float>(h, s);
			int intensity = cvRound(binVal * 255 / maxValue);
			rectangle(hist_2d, Point(h*scale, s*scale), Point((h + 1)*scale - 1, (s + 1)*scale - 1),
				Scalar::all(intensity));
		}
	}
	applyColorMap(hist_2d, hist_2d, COLORMAP_JET);
	imshow("2D灰度直方图", hist_2d);
}

123456789101112131415161718192021222324252627
```

# 24、直方图均衡化

## 所使用的API接口：

- equalizeHist()

## 代码演示：

```cpp
void QuickDemo::histogram_eq_demo(Mat &image) {
	Mat gray,dst;
	cvtColor(image, gray, COLOR_RGB2GRAY);
	equalizeHist(gray, dst);
	imshow("直方图均衡化", dst);
}
123456
```

# 25、均值滤波

## 所使用的API接口：

- blur()

## 代码演示：

```cpp
void QuickDemo::blur_demo(Mat &image) {
	Mat dst;
	blur(image, dst, Size(3, 3), Point(-1, -1));
	imshow("滤波图像", dst);
}
12345
```

# 26、高斯滤波

## 所使用的API接口：

- GaussianBlur()

## 代码演示：

```cpp
void QuickDemo::gaussian_blur_demo(Mat &image) {
	Mat dst;
	GaussianBlur(image, dst, Size(5, 5),5);
	imshow("高斯模糊", dst);
}
12345
```

# 27、双边线性滤波

## 所使用的API接口：

- bilateralFilter()

## 代码演示：

```cpp
void QuickDemo::bifilter_demo(Mat &image) {
	Mat dst;
	bilateralFilter(image, dst, 0, 100, 10);
	imshow("双边滤波", dst);
}
12345
```



文章知识点与官方知识档案匹配，可进一步学习相关知识
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



### Mat

**Mat的简单使用**

从实际出发，先看看他干啥的，怎么用。
一般我们用到Mat有两个重要的用途：
1.存储图像（其实图像可以看成一个高行宽列的一个矩阵）
2.存储矩阵

先来看看Mat用于图像和矩阵的最基本操作，读取一副图像，修改图像中某些像素的值，最后显示并保存，建立矩阵并进行矩阵运算
（以下例子采用最简单的方法，基本使用默认参数）

**简洁版**（如果你只想使用，而不想知道为什么、怎么改进）

```cpp
#include <iostream> //输入输出流头文件
#include <opencv2/opencv.hpp>  //OpenCV头文件
using namespace cv;//命名空间

int main()
{
	///
	1.Mat用于图像的读取、操作和存储
	///

	cv::Mat srcImage = cv::imread("D:/MyImage.jpg");	//读取
	cv::imshow("srcImage", srcImage);	//显示
	cv::Mat dstImage = srcImage.clone();	//赋值
	for (size_t i = 0; i < dstImage.rows; i++)	//对元素进行操作
	{
		for (size_t j = 0; j < dstImage.cols; j++)
		{
			//直观、安全、不会有i,j溢出的危险，读取速度慢
			dstImage.at<cv::Vec3b>(i, j)[0] *= 0.5;
			dstImage.at<cv::Vec3b>(i, j)[1] *= 0.5;
			dstImage.at<cv::Vec3b>(i, j)[2] = 255;
		}
	}
	cv::imshow("dstImage", dstImage);	//显示结果图
	cv::waitKey(1);	//延迟1ms，等待显示 若之后没有waitKey则显示窗口将在1ms后关闭
	cv::imwrite("D:/dstImage.jpg", dstImage);	//保存图像
	
	///
	2.Mat用于矩阵的应用，
	///
	//初始化
	cv::Mat rotationMatrix = (cv::Mat_<double>(3, 3) <<
		1.0, 2.0, 3.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0);
	cv::Mat A = cv::Mat::zeros(3, 3, CV_64F);	//全零矩阵
	cv::Mat B = cv::Mat::ones(3, 3, CV_64F);	//全一矩阵
	cv::Mat C = cv::Mat::eye(3, 3, CV_64F);	//单位矩阵

	A = B + C;   //加法
	A = B - C;   //减法
	A = B * C;   //矩阵乘法 必须满足矩阵相乘的行列数对应规则
	A = 5 * B;   //标量乘法 每个元素扩大5倍
	A = B.t();   //B转置
	A = B.inv(); //B逆矩阵
	//以上是最基本的操作，矩阵运算远远不是这几种，Mat包含了几乎所有的操作，用到的时候再查吧
	std::cout<<"A:"<<A<<std::endl;
	cv::waitKey(0); //当参数为0时 一直等待，为了显示窗口一直显示
	return 1;
}
```

**进阶版**（如果你想采用最适合的方法）

```cpp
//输入输出流头文件
#include <iostream> 
//头文件  opencv.hpp中包含基本的头文件 （我们采用的OpenCV版本是 2.4.13.6）
#include <opencv2/opencv.hpp>  

//命名空间，指明在cv下的所有类名、参数名、函数名等能够在不加 cv::下就能够使用
using namespace cv;

int main() 
{
	///
	1.Mat用于图像的读取、操作和存储
	///
	//创建一个Mat类型对象 image (以下出现的"cv::",如果添加了 using namespace cv；就可以省略)
	cv::Mat srcImage;
	
	//通过绝对路径读取一副BGR彩色图像，参数1是图像的绝对路径(注意:路径可采用"\\"或"/" 不能使用windows文件夹路径的"\");
	srcImage = cv::imread("D:/MyImage.jpg");
	
	//先显示image这个图像 参数1是显示窗口名称,参数2是Mat类型的对象;
	cv::imshow("srcImage", srcImage);
	
	//创建一个Mat类型对象 dstImage，
	//且分配给他一个srcImage.rows行，srcImage.cols列的空间，
	//数据类型是CV_8UC3，即3通道（C3）8bit的无符号整型（8U，uchar）
	//且将所有元素内所有通道值置0，Scalar::all(0)，这里修改"0"位置的值可得到你想要的值得矩阵
	//你也可以使用zeros函数达到全赋值为0效果;
	//cv::Mat dstImage = cv::Mat::zeros(srcImage.rows, srcImage.cols, CV_8UC3);
	//当然，因为我们之后要将srcImage给dstImage 所以此处直接使用 cv::Mat dstImage; 即可。
	cv::Mat dstImage(srcImage.rows,srcImage.cols,CV_8UC3,cv::Scalar::all(0));
	
	//将一个Mat A赋值给另一个Mat B，有四种方法
	//1.构造函数法         Mat A(B);
	//2.重载运算符法       A = B;
	//3.复制法            A.copyTo(B);
	//4.克隆法            B=A.clone();

	//这里需要知道一个Mat类的概念：
	//Mat 是一个类，由两个数据部分组成：矩阵头（包含矩阵尺寸，存储方法，存储地址等信息）
	//和一个指向存储所有像素值的矩阵（根据所选存储方法的不同矩阵可以是不同的维数）的指针。

	//方法1、2是浅拷贝（时间短，不安全），只拷贝矩阵头，不拷贝数据部分，A和B共用一块数据，A对元素的操作会影响B ；
	//方法3、4是深拷贝（时间长，相对安全），拷贝矩阵的所有数据，包括矩阵头，区别在于clone()会给目标矩阵重新分配新地址，
	//而copyTo()不会,copyTo()只是修改目标矩阵内的元素的值与当前矩阵值相同
	dstImage = srcImage.clone();
	
	//两层循环访问所有元素通道值，并将其中蓝色通道（B）减小一半，绿通道（G）值减小一半，红色通道（R）置255
	for (size_t i = 0; i < dstImage.rows; i++)
	{//外层循环行数
		for (size_t j = 0; j < dstImage.cols; j++)
		{//内层循环列数
		
			采用这种直观的方式，这种方法更安全不会有i,j溢出的危险，但是读取速度慢
			例如 图像为640x480分辨率，i，j取482、642改方法将会报错，但使用prt方法则一样会计算，不报错。
			//dstImage.at<cv::Vec3b>(i, j)[0] *= 0.5;
			//dstImage.at<cv::Vec3b>(i, j)[1] *= 0.5;
			//dstImage.at<cv::Vec3b>(i, j)[2] = 255;
			
			//ptr OpenCV中使用的智能指针，<>内是图像元素的类型 Vec3b 是一个包含三个uchar类型元素的一维数组
			//(i)[j][0]分别代表数据的行号、列号、和通道号,如果是单通道则(i)[j]即可，
			//由于opencv默认读取彩色图像是BGR，则0为蓝色、1为绿、2为红
			//uchar 能存储0~255的值 都为零则为黑色 都为255则为白色
			dstImage.ptr<cv::Vec3b>(i)[j][0] *= 0.5;
			dstImage.ptr<cv::Vec3b>(i)[j][1] *= 0.5;
			dstImage.ptr<cv::Vec3b>(i)[j][2] = 255;
		}
	}
	
	//创建一个名为dstImage的窗口用来显示图像，如果显示结束可通cv::destroyWindow("dstImage");进行指定销毁，
	//也可通过cv::destroyAllWindows();销毁存在的所有窗口。
	cv::namedWindow("dstImage");
	
	//显示结果图到名为dstImage的窗口中
	cv::imshow("dstImage", dstImage);

	//保存图像到某一地址，参数1.要保存的绝对路径和文件名，参数2.要保存的Mat图像
	cv::imwrite("D:/dstImage.jpg", dstImage);

	//延迟1ms秒时间等待键盘输入,如果参数为0则一直等待。在imshow之后，
	//如果没有waitKey语句则不会显示图像,若之后没有waitKey()则显示窗口将在1ms后关闭。
	cv::waitKey(1);	

	///
	2.Mat用于矩阵的应用，
	///
	//创建一个矩阵
	cv::Mat rotationMatrix;
	
	//给矩阵赋值，矩阵行列很小时，用这种方法直观、方便
	rotationMatrix = ( cv::Mat_<double>(3, 3) <<
						1.0, 2.0, 3.0,
						0.0, 1.0, 0.0,
						0.0, 0.0, 1.0);
						
	//如果是全零矩阵，可以如下进行初始化 当然 行、列和数据类型自己选择
	cv::Mat A = cv::Mat::zeros(3, 3, CV_64F);
	//如果是全一矩阵，可以如下进行初始化 当然 行、列和数据类型自己选择
	cv::Mat B = cv::Mat::ones(3, 3, CV_64F);
	//如果是单位矩阵，可以如下进行初始化 当然 行、列和数据类型自己选择
	cv::Mat C = cv::Mat::eye(3, 3, CV_64F);

	A = B + C; //加法
	A = B - C; //减法
	A = B * C; //矩阵乘法  必须满足矩阵相乘的行列数对应规则
	A = 5 * B; //标量乘法 每个元素扩大5倍
	A = B.t(); //B转置
	A = B.inv(); //B逆矩阵

	//以上是最基本的操作，矩阵运算远远不是这几种，Mat包含了几乎所有的操作，用到的时候再查吧
	
	//如果包含了c++输入输出流的头文件 #include <iostream> 那么Mat可输出至屏幕通过
	std::cout<<" A is : "<< A <<std::endl;
	
	//一直等待，以显示图像窗口
	cv::waitKey(0);
	cv::destroyAllWindows();	
	return 1;
}
```





**Mat的结构**

[OpenCV](https://so.csdn.net/so/search?q=OpenCV&spm=1001.2101.3001.7020)里数据的基本存储类型，意思是矩阵（Matrix）。因为数字图像可以看成矩阵，所以Mat不仅可以存储矩阵，更重要的他是图像的载体。一个Mat分为，Mat头和Mat数据两部分。Mat头部分大小是固定的，包含矩阵的大小，存储的方式，矩阵存储的地址等等，数据部分是一个指向矩阵包含像素值的指针（data）。



**头文件**

core.hpp 目前使用只要包含 opencv.hpp 即可，opencv.hpp包含了常用的头文件。

**命名空间**

cv
1.可以在包含头文件后添加 “using namespace cv；”之后代码可直接使用 Mat 类；
2.在不适用 “using namespace cv; ” ，在每次使用 Mat 都需使用cv命名空间，如，cv::Mat 。
（我习惯在使用时添加cv，这样的好处是在使用多个库编写程序时，不至于出现相同类名或方法名重名的状况，并且代码更加直观。）





#### **常用参数**

| 参数     | 类型   | 描述                                                         |
| -------- | ------ | ------------------------------------------------------------ |
| flags    | int    | Mat中的一些标记，一共32位，从低位到高位，包含了数据类型（0-2位）、通道数（3-11）等等， 具体请参考[【OpenCV】从Mat的flags中可以读到的信息，以及相关宏定义](https://blog.csdn.net/yiyuehuan/article/details/43701797) |
| data     | uchar* | 指向数据的指针                                               |
| dims     | int    | 矩阵的维度                                                   |
| rows     | int    | 矩阵行数 维度大于2 则rows = -1                               |
| cols     | int    | 矩阵列数 维度大于2 则cols = -1                               |
| size     | MSize  | 数据内是一维数组，有个两元素，size[0]矩阵的行数，size[1]矩阵的列数 |
| step     | MStep  | 数据内是一维数组，有个两元素，step[0]矩阵一行共多少字节，step[1]表示矩阵一个元素多少字节 |
| refcount | int*   | 矩阵数据的引用次数，浅拷贝得到的矩阵同步这个参数，同时增加或减少，可以用来判断有多少矩阵使用该矩阵的数据内容 |

**channels()** 通道数，矩阵每个像素可以存储一个数组，通道数是数组中元素的个数，常见的彩色图像，每个像素存蓝、绿、红（BGR）三个颜色，其channels = 3。

**type()** 表示了矩阵中元素的类型以及矩阵的通道个数，它是一系列的预定义的常量，其命名规则为CV_(位数）+（数据类型）+（通道数）。例如 CV_8UC1

**depth()** 矩阵中元素的一个通道的数据类型，这个值和type是相关的。例如 type为 CV_16SC2，一个2通道的16位的有符号整数。那么，depth则是CV_16S。depth也是一系列的预定义值，将type的预定义值去掉通道信息就是depth值:
CV_8U CV_8S CV_16U CV_16S CV_32S CV_32F CV_64F





**类型 type**

Mat中每个元素可以是单通道、三通道、多通道等等，其存储的数据类型也可能是char、uchar、short、ing、float、double等等。Mat对于这些类型进行了定义，即type，可以调用type()函数来返回当前Mat的类型。它是一系列的预定义的常量，表示了矩阵中元素的类型以及矩阵的通道个数，其命名规则为CV_(位数）+（数据类型）+（通道数）。具体的有以下值：

| type                         | 数据类型 |
| ---------------------------- | -------- |
| CV_8UC1、CV_8UC2、CV_8UC3    | uchar    |
| CV_8SC1、CV_8SC2、CV_8SC3    | char     |
| CV_16UC1、CV_16UC2、CV_16UC3 | ushort   |
| CV_16SC1、CV_16SC2、CV_16SC3 | short    |
| CV_32SC1、CV_32SC2、CV_32SC3 | int      |
| CV_32FC1、CV_32FC2、CV_32FC3 | float    |
| CV_64FC1、CV_64FC2、CV_64FC3 | double   |



**构造函数**

**1. Mat()**
无参构造方法无参构造方法；

**2. Mat(int rows, int cols, int type)**
创建行数为 rows，列数为 col，类型为 type 的图像；

**3. Mat(Size size, int type)**
创建大小为 size，类型为 type 的图像；

**4. Mat(int rows, int cols, int type, const Scalar& s)**
创建行数为 rows，列数为 col，类型为 type 的图像，并将所有元素初始化为值 s；

**5. Mat(Size size, int type, const Scalar& s)**
创建大小为 size，类型为 type 的图像，并将所有元素初始化为值 s；

**6. Mat(const Mat& m)**
将m赋值给新创建的对象，此处不会对图像数据进行复制，m和新对象共用图像数据，属于浅拷贝；

**7. Mat(int rows, int cols, int type, void\* data, size_t step=AUTO_STEP)**
创建行数为rows，列数为col，类型为type的图像，此构造函数不创建图像数据所需内存，而是直接使用data所指内存，图像的行步长由 step指定。

**8. Mat(Size size, int type, void\* data, size_t step=AUTO_STEP)**
创建大小为size，类型为type的图像，此构造函数不创建图像数据所需内存，而是直接使用data所指内存，图像的行步长由step指定。

**9. Mat(const Mat& m, const Range& rowRange, const Range& colRange)**
创建的新图像为m的一部分，具体的范围由rowRange和colRange指定，此构造函数也不进行图像数据的复制操作，新图像与m共用图像数据；

**10. Mat::Mat(const Mat& m, const Rect& roi)**
创建的新图像为m的一部分，具体的范围roi指定，此构造函数也不进行图像数据的复制操作，新图像与m共用图像数据。

------

构造函数原文：[浅谈Opencv Mat类（常用构造函数和成员函数整理）](https://blog.csdn.net/qq_37406130/article/details/78725406)

**赋值**

将一个Mat A赋值给另一个Mat B，有四种方法
1. 构造函数法    Mat A(B);
2. 重载运算符法   A = B;
3. 复制法     A.copyTo(B);
4. 克隆法     B=A.clone();

方法1、2是浅拷贝（时间短，不安全），只拷贝矩阵头，不拷贝数据部分，A和B共用一块数据，A对元素的操作会影响B。
方法3、4是深拷贝（时间长，相对安全），拷贝矩阵的所有数据，包括矩阵头，最大的区别在于clone()会给目标矩阵重新分配新地址，而copyTo()不会,copyTo()只是修改目标矩阵内的元素的值与当前矩阵值相同

**数据操作**

前面代码里也提到了，一般采用两种操作，1.使用at函数，2.使用prt函数。当然Mat对于数据的操作有很多方法，而我觉得这两种是最具有代表性的。
以一个数据类型为三通道无符号整型（uchar）的Mat A为例，即type为CV_8UC3。读取其中第一个通道的方法是：
`1. A.at<Vec3b>(i, j)[0]; 这里 A.at() 返回对指定数组元素的引用，这种方法会检查i，j是否越界相比较来说比较安全，但是速度相对慢一些。`
`2. A.ptr<Vec3b>(i)[j][0]; 这里 A.ptr() 返回指定矩阵行的指针，既然是指针，当发生越界的时候也不会出错而继续进行，这有可能修改别的数据，相比来说没那么安全，但是速度很快。`

#### 常用函数

```cpp
分配新的阵列数据
void Mat::create(int rows, int cols, int type)

如果数组有没有 elemens，则返回 true。
bool Mat::empty()

返回一个矩阵元素的类型
int Mat::type()

返回一个矩阵元素的深度
int Mat::depth()

返回通道数
int Mat::channels()

克隆
Mat Mat::clone()

把矩阵复制到另一个矩阵中
void Mat::copyTo(OutputArray m)

在缩放或不缩放的情况下转换为另一种数据类型
void Mat::convertTo(OutputArray m,int rtype,double alpha=1,double beta=0)

将阵列中所有的或部分的元素设置为指定的值
Mat& Mat::setTo(const Scalar& s, InputArray mask=noArray())

在无需复制数据的前提下改变2D矩阵的形状和通道数或其中之一
Mat Mat::reshape(int cn, int rows=0)

计算3元素向量的一个叉乘积
Mat Mat::cross(InputArray m)

更改矩阵的行数。
void Mat::resize(size_t sz)

返回数组元素的总数
size_t Mat::total()

返回矩阵元素大小 （以字节为单位）该方法返回以字节为单位的矩阵元素大小。
例如，如果矩阵类型是 CV_16SC3，该方法返回3*sizeof(short)或 6
size_t Mat::elemSize()

该方法通过矩阵表达式（matrix expression）实现矩阵的转置
The method performs matrix transposition by means of matrix expressions. 
它并未真正完成了转置但却返回一个临时的可以进一步用在更复杂的
矩阵表达式中或赋给一个矩阵的转置矩阵对象
MatExpr Mat::t()

该方法执行矩阵的反转矩阵表达。这意味着该方法返回一个临时矩阵反转对象并可进一步用于更复杂的
矩阵表达式的中或分配给一个矩阵。
DECOMP_LU是 LU 分解一定不能是单数的
DECOMP_CHOLESKY 是 Cholesky LLT只适用于对称正矩阵的分解。
该类型在处理大的矩阵时的速度是LU的两倍左右。
DECOMP_SVD是 SVD 分解。如果矩阵是单数或甚至不是2维，函数就会计算伪反转矩阵
MatExpr Mat::inv(int method=DECOMP_LU)
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



### .at<  >(  )

```cpp
if (dims == 1)//单通道
{
	int pv = image.at<uchar>(row, col);
	//读取为uchar类型(0-255 八位) 
	//转成int类型赋值给 pv  image.at
	image.at<uchar>(row, col) = 255 - pv;
}//遍历灰度图像并取反色图
1234567
```

```cpp
if (dims==3)
{
	Vec3b bgr=image.at<Vec3b>(row, col);//读取每个像素点的三个值bgr[0],bgr[1],bgr[2],赋值给bgr  可以用picture2.at<Vec3b>(i,j)[c]
	//给当前RGB色彩空间的像素三个颜色通道取反值
	image.at<Vec3b>(row, col)[0]=255-bgr[0];
	//像素 b通道 255-bgr[]:取图像反色
	image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
	//像素 g通道
	image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
	//像素 r通道
}//遍历彩色图像并取反色图
```



先扩展一下访问像素的 .at 的用法：

​     cv::mat的成员函数： .at(int y， int x)可以用来存取图像中对应坐标为（x，y）的元素坐标。但是在使用它时要注意，在编译期必须要已知图像的数据类型，这是因为cv::mat可以存放任意数据类型的元素。因此at方法的实现是用模板函数来实现的。假设提前已知一幅图像img的数据类型为 unsigned char型灰度图（单通道），要对坐标为(14,25)的像素重新赋值为25,则对应操作如下：

```cpp
srcImage.at<uchar>(14,25) = 25;
```

​     如果要操作的图片img是一幅数据类型同样为unsigned char的彩色图片，再次要求将坐标（14,25）的像素赋值为25。这个操作跟上面的就有点区别了，需要对这个像素三个通道的每个对应元素赋值,Opencv中图像三原色在内存中的排列顺序为B-G-R（见下面注释），操作过程如下：

```cpp
img.at<Vec3b>(14,25) [0]= 25;//B  
img.at< Vec3b >(14,25) [1]= 25;//G  
img.at< Vec3b >(14,25 [2]= 25;//R  
```

一个简单小程序：

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat m(3, 3, CV_8UC3);//建立一个三行三列3通道像素
	Vec3b p;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p[0] = i;
			p[1] = j;
			p[2] = i+j;
			m.at<Vec3b>(i,j) = p;
		}
	}
	cout <<"数组:"<<endl<<"M= " << m << endl;
	int a = m.at<Vec3b>(2, 2)[2];
	Vec3b b = m.at<Vec3b>(2, 2)[2];
	cout << "访问一个数：" << a <<endl<<"访问三通道："<<b<<endl;
	waitKey(0);
	return 0;
}
```





#### uchar

uchar是无符号的字符类型，数值范围为0～255,在图像处理中表示像素值范围时用的多

#### Vec3b

表示每一个Vec3b对象中,存储3个char字符型数据,可以去存储RGB图像中的一个像素点
例1
描述一种RGB颜色：

```cpp
Vec3b color;
color[0]=0;//B分量
color[1]=0;//G分量
color[2]=255;//R分量
```

1.文件包含:     

​           首先在程序开头处加上#include<vector>以包含所需要的类文件vector,还有一定要加上using namespace std;

2.声明一个int向量以替代一维的数组:vector <int> a;(等于声明了一个int数组a[],大小没有指定,可以动态的向里面添加删除。

比如Vec<uchar, 3>：
其实这句就是定义一个uchar类型的数组，长度为3而已，例如 8U 类型的 RGB 彩色图像可以使用 <Vec3b>，3 通道 float 类型的矩阵可以使用 <Vec3f>。对于 Vec 对象，可以使用[]符号如操作数组般读写其元素，如：Vec3b color; //用 color 变量描述一种 RGB 颜色
color[0]=255; //0通道的B 分量
color[1]=0; //1通道的G 分量
color[2]=0; //2通道的R 分量



### .ptr<  >()

**返回指定位置的指针**

```cpp
//定义
_Tp* Mat::ptr(int y)
{
    CV_DbgAssert( y == 0 || (data && dims >= 1 && (unsigned)y < (unsigned)size.p[0]) );
    return (_Tp*)(data + step.p[0] * y);
}
123456
```

例4

```cpp
//指针类型为 uchar
uchar* current_row = image.ptr<uchar>(row);
//指向第row行的第一个元素
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
# 课程查询使用手册



## 课程爬取

每次使用时，需先通过浏览器登录选课网页，然后通过检查功能，获取页面cookie

将得到的cookie粘贴到 /conf/search.json 中，作为键cookie的值

或者清除search中cookie的值，将得到的cookie粘贴到 /conf/cookie.txt 中，程序会自动将txt中的cookie添加到变量

如果想要清除search内的值，可以运行 util/initJSON.py

程序会对search表单初始化

下面是search中各参数的意义

|    变量名    |   含义   |
| :----------: | :------: |
| courseSerial | 课程序号 |
|  courseCode  | 课程代码 |
|  courseName  | 课程名称 |
|  courseType  | 课程类别 |
|    campus    | 开课校区 |
|  className  |  教学班  |
|   semester   | 学期代码 |

注：学期代码可以通过查看网页源代码获取，如 2022-2023 学年第二学期代码为 77

将搜索项填好后，运行 src/courseGetter.py 爬取选课列表，

课程内容会存放在 File/Course/ 文件夹下，对应的时间表会存放在 File/Time/ 文件夹下

不建议按课程序号和课程代码搜索（这个大概自己手动搜会更快一点？）

搜索样例：

```json
{
    "cookie": "",
    "courseSerial": "",
    "courseCode": "",
    "courseName": "大学英语2",
    "courseType": "",
    "campus": "北洋园",
    "className": "2022"
    "semester": "77"
}
```

```json
{
    "cookie": "",
    "courseSerial": "",
    "courseCode": "",
    "courseName": "",
    "courseType": "选修",
    "campus": "北洋园",
    "className": "2022级"
    "semester": "77"
}
```



## 表格生成

表格生成的主程序为 src/tableMain.py


表格生成有两种模式

一种是将课程名称作为第一列输出，输出函数为  tableCreater.tableCreateType()

另一种是将教师姓名作为第一列输出，输出函数为  tableCreater.tableCreateName()

对于两种输出函数

搜索选修课可以使用 tableCreateType() ，搜索英语课可以使用 tableCreateName()

生成的表格存储在 Files/Return/ 中


表格每一行表示一节课程

表格列从左至右表示课程名称/教师名称，星期一 1-2， 星期一 3-4 ......

每日课程表示五节，每周课程从周一到周五，最后一列表示课程序号，可作为课程的精确搜索方式

表格中存储 1 的单元格代表该课程在对应的时间不会有必修课冲突



## Excel制作

生成的表格格式为 .csv，为了方便排版，需要将表格数据导入 excel 中

导入方法为，在 Excel 任务栏选择“数据”，选择“从文本/CSV导入”

导入后会生成一张新的表格

如需翻转构图，可以复制表格，并在粘贴的右键下拉栏中选择“选择性粘贴”，“转置”

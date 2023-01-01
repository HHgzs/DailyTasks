# 课程查询使用手册

每次使用时，需先通过浏览器登录选课网页，然后通过检查功能，获取页面cookie

将得到的cookie粘贴到 /File/search.json 中，作为键cookie的值

或者清除search中cookie的值，将得到的cookie粘贴到 /File/cookie.txt 中，程序会自动将txt中的cookie添加到变量



如果想要清除search内的值，可以运行 initJSON.py

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


将搜索项填好后，运行 courseGetter.py 爬取选课列表，

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
}
```


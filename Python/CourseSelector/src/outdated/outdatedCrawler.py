import requests
import re
import csv
import time

courseSerial = ""
courseCode = ""
courseName = ""
courseType = "选修"
campus = "北洋园"
className = "2022级"


pageNum = 1
initURL = "http://classes.tju.edu.cn/eams/stdSyllabus!search.action"


def plusStr(str):
    return str + "&"


courseSerialInput = "lesson.no=" + courseSerial
courseCodeInput = "lesson.course.code=" + courseCode
courseNameInput = "lesson.course.name" + courseName
courseTypeInput = "multiOrCourseType.name=" + courseType
campusInput = "lesson.campus.name=" + campus
classNameInput = "lesson.teachClass.name=" + className
pageInput = "pageNo="

initURL += "?" + plusStr(courseTypeInput) + plusStr(campusInput) + plusStr(
    classNameInput) + pageInput

with open("CourseSelection/Files/cookie.txt", "r") as fCookie:
    Cookie = fCookie.readline()
    fCookie.close()

headers = {
    'User-Agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36 Edg/108.0.1462.54",
    'Host': "classes.tju.edu.cn",
    'Cookie': Cookie
}

num = 1
while num:
    url = initURL
    url += str(pageNum)
    resp = requests.get(url, headers=headers)
    page_content = resp.text
    print(url)

    if pageNum == 1:
        objNum = re.compile(
            r'pageInfo.*?[,](?P<itemsNum>.*?)[,](?P<pageNum>.*?)[);]', re.S)
        result = objNum.finditer(page_content)

        for it in result:
            itemsNum = it.group("itemsNum")
            pageTotal = it.group("pageNum")
            num = int(int(pageTotal) / int(itemsNum)) + 1
        print(num)

        with open("CourseSelection/Files/initHtml.txt", "w",
                  encoding="utf-8") as fileTXT:
            fileTXT.write(page_content)
            fileTXT.close

    objPage = re.compile(
        r'<td class="gridselect">.*?<td>(?P<task_code>.*?)</td>'
        r'<td>(?P<course_code>.*?)</td>.*?title.*?">(?P<name>.*?)'
        r'</a>.*?<td>(?P<type>.*?)</td><td>(?P<hours>.*?)</td><td>(?P<credits>.*?)</td>',
        re.S  # 匹配换行
    )

    objPage2 = re.compile(
        r'<td class="gridselect">.*?name.*?lesson.id.*?value="(?P<class_id>.*?)" type.*?</td>'
        r'<td>(?P<task_code>.*?)</td>'
        r'<td>(?P<course_code>.*?)</td>.*?title.*?">(?P<name>.*?)'
        r'</a>.*?<td>(?P<type>.*?)</td><td>(?P<hours>.*?)</td><td>(?P<credits>.*?)</td>',
        re.S  # 匹配换行
    )

    objTime = re.compile(
        r"contents[[]'(?P<course_code>.*?)'[]]=.*?星期(?P<day_cn>.) (?P<begin_time>.)-"
    )

    result = objTime.finditer(page_content)

    with open("CourseSelection/Files/CourseTime.csv", "a", encoding="utf-8", newline='') as fCourse:
        writer = csv.writer(fCourse)
        for it in result:
            dic = it.groupdict()
            writer.writerow(dic.values())
        fCourse.close()

    result = objPage2.finditer(page_content)

    with open("CourseSelection/Files/Course.csv", "a", encoding="utf-8", newline='') as fCourse:
        writer = csv.writer(fCourse)
        for it in result:
            dic = it.groupdict()
            writer.writerow(dic.values())
        fCourse.close()

    resp.close()
    num -= 1
    print("Page %d, %d left" % (pageNum, num))
    pageNum += 1
    time.sleep(1)

print("over")

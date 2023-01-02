import requests
import re
import csv
import time
import json

dataRead = dict()
with open("CourseSelection/conf/search.json", "r", encoding="utf-8") as jsonFile:
    dataRead = json.load(jsonFile)


def plusStr(str):
    return str + "&"


def fileNameInit(dataRead):
    name = "Of"
    name += dataRead['courseName']
    if dataRead['courseName'] == "":
        name += dataRead['courseType']
        if dataRead['courseType'] == "":
            name += dataRead['className']
    return name


Cookie = dataRead["cookie"]
semesterInput = "lesson.semester.id=" + dataRead["semester"]
courseSerialInput = "lesson.no=" + dataRead["courseSerial"]
courseCodeInput = "lesson.course.code=" + dataRead["courseCode"]
courseNameInput = "lesson.course.name=" + dataRead['courseName']
courseTypeInput = "multiOrCourseType.name=" + dataRead['courseType']
campusInput = "lesson.campus.name=" + dataRead['campus']
classNameInput = "lesson.teachClass.name=" + dataRead['className']
pageInput = "pageNo="
pageNum = 1

fileName = fileNameInit(dataRead)

initURL = "http://classes.tju.edu.cn/eams/stdSyllabus!search.action"

initURL += "?" + plusStr(semesterInput) + plusStr(courseSerialInput) + plusStr(
    courseCodeInput) + plusStr(courseNameInput) + plusStr(
        courseTypeInput) + plusStr(campusInput) + plusStr(
            classNameInput) + pageInput

if Cookie == "":
    with open("CourseSelection/conf/cookie.txt", "r") as fCookie:
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

        FileDirc = "CourseSelection/Files/Html/Html" + fileName + ".html"
        with open(FileDirc, "w",
                  encoding="utf-8") as fileTXT:
            fileTXT.write(page_content)
            fileTXT.close

    objPage = re.compile(
        r'<td class="gridselect">.*?name.*?lesson.id.*?value="(?P<class_id>.*?)" type.*?</td>'
        r'<td>(?P<task_code>.*?)</td>'
        r'<td>(?P<course_code>.*?)</td>.*?title.*?">(?P<name>.*?)'
        r'</a>.*?<td>(?P<type>.*?)</td><td>(?P<hours>.*?)</td><td>(?P<credits>.*?)</td>',
        re.S  # 匹配换行
    )

    objPage2 = re.compile(
        r'<td class="gridselect">.*?name.*?lesson.id.*?value="(?P<class_id>.*?)" type.*?</td>'
        r'<td>(?P<task_code>.*?)</td>'
        r'<td>(?P<course_code>.*?)</td>.*?title.*?">(?P<name>.*?)</a>.*?'
        r'<td>(?P<type>.*?)</td><td>.*?</td><td>.*?</td>'
        r'<td>(?P<teacher>.*?)</td><td>.*?</td.*?td>.*?</td.*?td>(?P<credits>.*?)'
        r'</td.*?td>(?P<hours_week>.*?)</td>',
        re.S  # 匹配换行
    )

    objPage3 = re.compile(
        r'<td class="gridselect">.*?name.*?lesson.id.*?value="(?P<class_id>.*?)" type.*?</td>'
        r'<td>(?P<task_code>.*?)</td>'
        r'<td>(?P<course_code>.*?)</td>.*?title.*?">(?P<name>.*?)</a>.*?'
        r'<td>.*?</td><td>.*?</td><td>.*?</td>'
        r'<td>(?P<teacher>.*?)</td><td>.*?</td.*?td>.*?</td.*?td>(?P<credits>.*?)'
        r'</td.*?td>(?P<hours_week>.*?)</td>',
        re.S  # 匹配换行
    )

    objTime = re.compile(
        r"contents[[]'(?P<course_code>.*?)'[]]=.*?星期(?P<day_cn>.) (?P<begin_time>.)-"
    )

    result = objTime.finditer(page_content)

    FileDirc = "CourseSelection/Files/Time/Time" + fileName + ".csv"
    with open(FileDirc, "a", encoding="utf-8", newline='') as fCourse:
        writer = csv.writer(fCourse)
        for it in result:
            dic = it.groupdict()
            writer.writerow(dic.values())
        fCourse.close()

    result = objPage3.finditer(page_content)

    FileDirc = "CourseSelection/Files/Course/Course" + fileName + ".csv"
    with open(FileDirc, "a", encoding="utf-8", newline='') as fCourse:
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

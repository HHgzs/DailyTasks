import json

# data = {
#     "courseSerial": "",
#     "courseCode": "",
#     "courseName": "",
#     "courseType": "选修",
#     "campus": "北洋园",
#     "className": "2022级"
# }

# with open("CourseSelection/Files/search.json", "w", encoding="utf-8") as jsonFile:
#     json.dump(data, jsonFile, ensure_ascii=False)
#     print("successfully create jsonFile")

dataRead = dict()
with open("CourseSelection/Files/search.json", "r",
          encoding="utf-8") as jsonFile:
    dataRead = json.load(jsonFile)
print(dataRead)

# courseSerial = ""
# courseCode = ""
# courseName = ""
# courseType = "选修"
# campus = "北洋园"
# className = "2022级"

courseSerialInput = "lesson.no=" + dataRead["courseSerial"]
courseCodeInput = "lesson.course.code=" + dataRead["courseCode"]
courseNameInput = "lesson.course.name=" + dataRead['courseName']
courseTypeInput = "multiOrCourseType.name=" + dataRead['courseType']
campusInput = "lesson.campus.name=" + dataRead['campus']
classNameInput = "lesson.teachClass.name=" + dataRead['className']
pageInput = "pageNo="

# print(courseTypeInput)
# print(campusInput)


def plusStr(str):
    return str + "&"


initURL = "http://classes.tju.edu.cn/eams/stdSyllabus!search.action"

initURL += "?" + plusStr(courseSerialInput) + plusStr(
    courseCodeInput) + plusStr(courseNameInput) + plusStr(
        courseTypeInput) + plusStr(campusInput) + plusStr(
            classNameInput) + pageInput + "1"

print(initURL)

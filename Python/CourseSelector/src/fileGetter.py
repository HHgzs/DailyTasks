import os
import json


class fileGetter:

    def getDirc():
        fileOfCourseDict = dict()
        num = 1
        path = "CourseSelection/Files/Course"
        fileDirc = ""
        print("Choose input file:")
        for file_name in os.listdir(path):
            fileOfCourseDict[num] = file_name
            strl = str(num) + " " + file_name
            print(strl)
            num += 1
        while True:
            inputNum = int(input())
            if inputNum in fileOfCourseDict:
                fileDirc = fileOfCourseDict[inputNum]
                print(fileDirc + " is choosen")
                break
            else:
                print("Error Input")
        fileDircOfCourse = "CourseSelection/Files/Course/" + fileDirc
        fileDircOfTime = "CourseSelection/Files/Time/" + fileDirc.replace(
            "Course", "Time")
        fileDircOfReturn = "CourseSelection/Files/Return/" + fileDirc.replace(
            "Course", "Return")
        print(fileDircOfCourse)
        print(fileDircOfTime)

        dircOutput = {
            "fileDircOfCourse": fileDircOfCourse,
            "fileDircOfTime": fileDircOfTime,
            "fileDircOfReturn": fileDircOfReturn
        }

        with open("CourseSelection/conf/dirc.json", "w",
                  encoding="utf-8") as jsonFile:
            json.dump(dircOutput, jsonFile, ensure_ascii=False)
            print("successfully create jsonFile")

        return dircOutput

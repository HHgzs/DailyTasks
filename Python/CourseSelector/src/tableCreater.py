import csv
import json
# from fileGetter import fileGetter


class tableCreater:

    def plusStr(strDay, numTime):
        dayOfWeek = {
            "一": "Mon_",
            "二": "Tue_",
            "三": "Wed_",
            "四": "Thur_",
            "五": "Fri_"
        }
        time = ('1', '3', '5', '7', '9')
        if strDay in dayOfWeek and numTime in time:
            return dayOfWeek[strDay] + numTime
        else:
            return "0"

    def readStr(strClass):
        with open("CourseSelection/conf/rowCts.json", "r", encoding="utf-8") as jsonFile:
            rowCts = json.load(jsonFile)
            return rowCts[strClass]

    def getID():

        availableID = dict()
        dictClass = dict()
        fileDirc = dict()
        with open("CourseSelection/conf/class.json", "r", encoding="utf-8") as jsonFile:
            dictClass = json.load(jsonFile)
            jsonFile.close()
        with open("CourseSelection/conf/dirc.json", "r", encoding="utf-8") as jsonFile:
            fileDirc = json.load(jsonFile)
            jsonFile.close()

        with open(fileDirc["fileDircOfTime"], 'r', encoding='utf-8') as file_obj:
            reader = csv.reader(file_obj)
            for row in reader:
                classTime = tableCreater.plusStr(row[1], row[2])
                if classTime != "0":
                    if dictClass[classTime] == 0:
                        availableID[row[0]] = classTime
        # for item in availableID:
        #     print(item + " // " + availableID[item])
        # print(availableID)
        # tableDict = tableCreater.CourseReader(fileDirc["fileDircOfCourse"], availableID)
        return availableID

    def CourseReader(availableID):
        tableDict = dict()
        tempDict = dict()

        with open("CourseSelection/conf/dirc.json", "r", encoding="utf-8") as jsonFile:
            fileDirc = json.load(jsonFile)
            jsonFile.close()

        fileDirc = fileDirc["fileDircOfCourse"]

        with open(fileDirc, 'r', encoding='utf-8') as file_obj:
            reader = csv.reader(file_obj)
            for row in reader:
                line = (row[1], row[2], row[3], row[4])
                tempDict[row[0]] = line

        for item in availableID:

            line = tempDict[item]
            num = tableCreater.readStr(availableID[item])
            newLine = (num, line[0], line[1], line[2], line[3])
            tableDict[item] = newLine

        return tableDict

    def tableCreateType(tableDict):

        with open("CourseSelection/conf/dirc.json", "r", encoding="utf-8") as jsonFile:
            fileDirc = json.load(jsonFile)
            jsonFile.close()

        dirc = fileDirc["fileDircOfReturn"]

        with open(dirc, 'w', encoding='utf-8', newline='') as file_obj:
            writer = csv.writer(file_obj)
            for item in tableDict:
                row = [" "]*27
                row[0] = tableDict[item][3]
                row[tableDict[item][0]] = "1"
                row[26] = tableDict[item][1]

                writer.writerow(row)
            print("Save as " + dirc)

    def tableCreateName(tableDict):

        with open("CourseSelection/conf/dirc.json", "r", encoding="utf-8") as jsonFile:
            fileDirc = json.load(jsonFile)
            jsonFile.close()

        dirc = fileDirc["fileDircOfReturn"]

        with open(dirc, 'w', encoding='utf-8', newline='') as file_obj:
            writer = csv.writer(file_obj)
            for item in tableDict:
                row = [" "]*27
                row[0] = tableDict[item][4]
                row[tableDict[item][0]] = "1"
                row[26] = tableDict[item][1]

                writer.writerow(row)
            print("Save as " + dirc)

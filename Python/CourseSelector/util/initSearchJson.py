import json

data = {
    "cookie": "",
    "courseSerial": "",
    "courseCode": "",
    "courseName": "",
    "courseType": "",
    "campus": "",
    "className": "",
    "semester": "77"

}

with open("CourseSelection/conf/class.json", "w", encoding="utf-8") as jsonFile:
    json.dump(data, jsonFile, ensure_ascii=False)
    print("successfully create jsonFile")

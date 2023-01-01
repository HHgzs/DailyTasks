import json

data = {
    "cookie": "",
    "courseSerial": "",
    "courseCode": "",
    "courseName": "",
    "courseType": "",
    "campus": "",
    "className": ""
}

with open("CourseSelection/Files/search.json", "w", encoding="utf-8") as jsonFile:
    json.dump(data, jsonFile, ensure_ascii=False)
    print("successfully create jsonFile")

import json

data_0 = {
    "Mon_1": 0,
    "Mon_3": 0,
    "Mon_5": 0,
    "Mon_7": 0,
    "Mon_9": 0,
    "Tue_1": 0,
    "Tue_3": 0,
    "Tue_5": 0,
    "Tue_7": 0,
    "Tue_9": 0,
    "Wed_1": 0,
    "Wed_3": 0,
    "Wed_5": 0,
    "Wed_7": 0,
    "Wed_9": 0,
    "Thur_1": 0,
    "Thur_3": 0,
    "Thur_5": 0,
    "Thur_7": 0,
    "Thur_9": 0,
    "Fri_1": 0,
    "Fri_3": 0,
    "Fri_5": 0,
    "Fri_7": 0,
    "Fri_9": 0
}

data_1 = {
    "Mon_1": 1,
    "Mon_3": 1,
    "Mon_5": 1,
    "Mon_7": 1,
    "Mon_9": 1,
    "Tue_1": 1,
    "Tue_3": 1,
    "Tue_5": 1,
    "Tue_7": 1,
    "Tue_9": 1,
    "Wed_1": 1,
    "Wed_3": 1,
    "Wed_5": 1,
    "Wed_7": 1,
    "Wed_9": 1,
    "Thur_1": 1,
    "Thur_3": 1,
    "Thur_5": 1,
    "Thur_7": 1,
    "Thur_9": 1,
    "Fri_1": 1,
    "Fri_3": 1,
    "Fri_5": 1,
    "Fri_7": 1,
    "Fri_9": 1
}


# i = 1
# for item in data_1:
#     data_1[item] = i
#     i += 1

with open("CourseSelection/conf/class.json", "w",
          encoding="utf-8") as jsonFile:
    json.dump(data_1, jsonFile, ensure_ascii=False)
    print("successfully create jsonFile")

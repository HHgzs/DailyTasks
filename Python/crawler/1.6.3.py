import requests

url = "https://movie.douban.com/j/chart/top_list?type=17&interval_id=100%3A90&action=&start=0&limit=20"

# 重新封装参数

param = {
    "type": "17",
    "interval_id": "100:90",
    "action": "",
    "start": 0,
    "limit": 20,
}

# 可以通过更改参数获得更多数据

headers = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.42"
}
resp = requests.get(url=url, params=param, headers=headers)

print(resp.json())

resp.close()
# 关掉resp

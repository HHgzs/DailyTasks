import requests

question = input("输入搜索")
url = 'https://www.sogou.com/web?query={question}'

dic = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.42"
}

resp = requests.get(url, headers=dic)

print(resp)
print(resp.text)
with open("crawler/1.6.html", mode="w", encoding="utf-8") as f:
    f.write(resp.text)
print("over")

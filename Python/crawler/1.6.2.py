import requests

url = "https://fanyi.baidu.com/sug"

word = input("Enter your word: ")

dic = {
    "kw": word
}

resp = requests.post(url, data=dic)
print(resp.json())

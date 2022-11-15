# # 需求：用程序模拟浏览器，输入一个网址，从该网址中获取到资源或者内容
# from urllib.request import urlopen
# # 确定要爬取网址的路径
# url = "http://www.baidu.com"
# # 访问网址得到相应
# resp = urlopen(url)
# # 想得到内容
# # decode 就是为了解码,以utf-8的形式解码
# # print(resp.read().decode("utf-8"))
# with open("mybaidu.html", mode="w", encoding="utf-8") as f:
#     f.write(resp.read().decode("utf-8"))  # 从响应中读取到页面源代码
# print("ok")

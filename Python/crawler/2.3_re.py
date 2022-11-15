import re

# findall 匹配字符串中所有符合的正则表达式

lst = re.findall(r"\d+", "明早0845出门核酸, 1030开始上课")
print(lst)


# finditer 匹配所有，返回迭代器，效率高
# 需要  .group()  拿到数据

it = re.finditer(r"\d+", "明早0845出门核酸, 1030开始上课")
for i in it:
    print(i.group())


# search 返回match对象，需要  .group()  拿到数据
# 找到一个结果就返回

s = re.search(r"\d+", "明早0845出门核酸, 1030开始上课")
print(i.group())


# match从头开始匹配

s = re.match(r"\d+", "0845出门核酸, 1030开始上课")
print(s.group())


# 预加载正则表达式
obj = re.compile(r"\d+")

ret = obj.finditer("明早0845出门核酸, 1030开始上课")
for it in ret:
    print(it.group())

ret = obj.findall("现在的时间是2022.11.15 22:53")
print(ret)

import random

print("+----------------------------+")
print("+                            +")
print("+   欢迎进入石头剪刀布游戏   +")
print("+                            +")
print("+----------------------------+")

arr = {'剪刀': 0, '石头': 1, '布': 2}
arr2 = ('剪刀', '石头', '布')
a = random.randint(0, 2)
str = input("请输入您的出拳：")
if str in arr:
    b = arr[str]
    print("对方的出拳是%s" % arr2[a])
    if b - a == 1 or b - a == -2:
        print("恭喜，您赢了！")
    elif a == b:
        print("平局!")
    else:
        print("抱歉，您输了！")
else:
    print("抱歉，请输入石头、剪刀、布")

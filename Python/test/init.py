print("Hello VScode")
texts = "Python"
print(texts)
#   int     long    float   complex
#   bo

a = "abc"
b = 123.3
b = int(b)
c = 0.5
print(a)
print(b)
d = str(b)
print(b)

print(bool(''))
print(bool(""))
print(bool(0))
print(bool({}))
print(bool([]))
print(bool(()))

print(d * 3)

print("number is %d %d, word is %s" % (b, c, a))

if b == 123:
    print("Yes")
elif b > 123:
    print("elif")
else:
    print("No")

for s in "Hello":
    print(s)
for i in range(5):
    print(i)
for i in range(3, 12, 5):
    print(i)

str1 = "test class string in Python"
print(str1.find('c'))

str2 = ['test', 'class', 'string', 'in', 'Python']
str3 = ['again', '?']
print(len(str1))
temp = "."
str2.append(temp)
str2.insert(1, 'the')
str2.extend(str3)
print(str1)
print(str2)

findWord1 = 'class'
findWord2 = 'string'
if findWord1 in str2:
    print("Yes")
else:
    print("No")
if findWord2 not in str2:
    print("No")
else:
    print("Yes")

print(str2)
del str2[7]
print(str2)
str2.pop

tuple = ('hello', 1024, 3.14)
print(tuple[0])

print(str2[0:4:2])

info = {'name': 'HHgzs', 'age': '18', 'school': 'NULL'}
print(info)
info['school'] = 'TJU'
print(info)
info['hobby'] = 'photography'
print(info)
del info['hobby']
print(info)

for i in info.keys():
    print(i)
for i in info.values():
    print(i)
for i in info.items():
    print(i)
for i, j in info.items():
    print("key = %s, value = %s" % (i, j))

info.clear()


def function1():
    print("This is a function")
    print("HERE")


def function2(a, b):
    c = a + b
    return c


print(function2(1, 1))

f = open('test.txt', '')

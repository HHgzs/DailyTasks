def isprime(n):  # 判断素数函数
    a = 0
    m = int(pow(n, 0.5)) + 1
    for i in range(2, m + 1):
        if n % i == 0:
            break
        elif n % i != 0 and i == m:
            a = 1
    return (a)


def f(n):  # 找小于n的素数并求和
    ls = [2]
    for i in range(2, n + 1):
        a = isprime(i)
        if a == 0:
            continue
        elif a == 1:
            ls.append(i)

    lm = ls[-10:]
    #    print(l)
    #    print(ls)
    sum = 0
    for j in lm:
        sum += j
    return (sum)


p = int(input())
print(f(p))

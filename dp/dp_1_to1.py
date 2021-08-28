# -*- coding: utf-8 -*-
x = 6

d = [0] * 10

# bottom-up
for i in range(2, x+1):
    # 현재의 수에서 1을 빼는 경우,
    d[i] = d[i-1] + 1

    # print("i: {0}, i//{0}: {2}".format(i, i//2))

    n = 0
    # i(인덱스)는 숫자를 의미, d[i//n](값)은 인덱스(숫자)에 도달할 때까지의 최소 경우의 수를 의미.
    if i % 2 == 0:
        d[i] = min(d[i], d[i//2] + 1)
        n = 2
        print("(i: {0}, i//{1}: {2}): ({3}, {4})".format(i, n, i//n, d[i], d[i//n]))
        print(d)
    if i % 3 == 0:
        d[i] = min(d[i], d[i//3] + 1)
        n = 3
        print("(i: {0}, i//{1}: {2}): ({3}, {4})".format(i, n, i//n, d[i], d[i//n]))
        print(d)
    if i % 5 == 0:
        d[i] = min(d[i], d[i//5] + 1)
        n = 5
        print("(i: {0}, i//{1}: {2}): ({3}, {4})".format(i, n, i//n, d[i], d[i//n]))
        print(d)

    # print("i: {0}, i//{1}: {2}".format(i, n, i//n))
    # print(d)
    print(" ")

print(d[x])

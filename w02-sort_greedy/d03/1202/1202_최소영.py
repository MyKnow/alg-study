import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
dia = [(0, 0)] * 300000

for i in range(n):
    m, v = map(int, input().split())
    dia[i] = (m, v)

dia.sort(key=lambda x: -x[1])

sum = 0
dia = deque(dia)

for _ in range(k):
    c = int(input())

    for weight, price in dia:
        if c >= weight:
            sum += price
            dia.remove((weight, price))
            break

print(sum)

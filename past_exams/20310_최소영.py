import sys
input = sys.stdin.readline

s = input().strip()

dict = {'0': 0, '1': 0}

for x in s:
    dict[x] += 1

for key, value in dict.items():
    dict[key] = value // 2

answer = ''
for key, value in dict.items():
    for _ in range(value):
        answer += key

print(answer)

import sys
from collections import deque
input = sys.stdin.readline
m, n = map(int, input().split())

mymap = [0]*(m+1)
for i in range(m):
    line = list(map(int, input().split()))
    mymap[i] = line


dp = [[0]*(n) for _ in range(m)]
def bfs(vx,vy):
    q = deque([[vx,vy]])
    # 출발은 한가지 경우의 수
    dp[vx][vy] = 1
    while q:
        a,b = q.popleft()
        left = b-1
        right = b+1
        down = a+1

        # 왼쪽으로 이동
        # print("왼쪽으로: ", a,left)
        if left>=0 and mymap[a][b]>mymap[a][left]:
            dp[a][left] += 1
            q.append([a,left])
        # 오른쪽으로 이동
        # print("오른쪽으로: ", a,right)
        if right < n and mymap[a][b]>mymap[a][right]:
            dp[a][right] += 1
            q.append([a,right])
        # 아래로 이동
        # print("아래로: ", down,b)
        if down<m and mymap[a][b]>mymap[down][b]:
            dp[down][b] += 1
            q.append([down,b])
        # for row in dp:
        #     print(row)
        # print()
bfs(0,0)

print(dp[m-1][n-1])

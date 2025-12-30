# 한번에 가로3 세로1 or 가로 1 세로 3 씩만 움직임
# dfs? bfs?
# 맨 첫줄 : 테케 개수
# 테케 첫줄: 체스판의 한 변의 길이(정사각형)
# 둘째줄 나이트가 현재 있는 칸
# 셋째줄 나이트가 이동하려고 하는 칸

# 출력: 테스트케이스마다 나이트가 최소 몇번만에 이동할 수 있는지

# 생각: 방향마다 노드를 확장해나가면서 bfs로 풀어보기 -> 최초로 도달하면 반복 종료하고 이동횟수 출력
# 이미 갔던 노드는 되돌아가지 않기->방문그래프 필요
# 2차원 deque는 어떻게 저장해야하지
# deque에 튜플로 순서 저장되는지 모르겠음

from collections import deque

c = int(input())

    
move = [[-2, 1], [-2, -1], [-1, 2], [-1, -2], [1, 2], [1, -2], [2, 1], [2, -1]]
def bfs(vx, vy, tx, ty):
    depth = 0
    flag = 0
    q = deque([(vx, vy)])
    graph[(vx, vy)] = True
    while q:
        (vx, vy) = q.popleft()
        # 그래프 깊이 저장해야함
        # for문으로 체스 이동범위 한정
        for [mx, my] in move:
            i = max(0, vx + mx)
            j = min(l-1, vy + my)
            # 방문한적 없으면서 도달못했으면 append, 도달했으면 종료하고 리턴
            if graph[(i, j)] == False:
                q.append((i, j))
                graph[(i, j)] = True
                if i == tx and j == ty:
                    flag = 1
                    break
        # x, y for 문 한번씩 다 돌아야 depth 증가
        depth = depth + 1
        if flag == 1:
            break
    print(depth)
            
for i in range(c):
    l = int(input())
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    graph = [[False]*(l+1) for _ in range(l+1)]
    bfs(x1, y1, x2, y2)




# 모든 지점에 대해서 목표지점까지의 거리 구하기
# 지도의 크기 n = height / m = width (2~1000)

# 1. 입력
    # 0 -> 갈 수 없는 땅
    # 2 -> 목표지점
# 2. 출력
    # 0 -> 원래 갈 수 없는 땅 (목표 지점 포함?)
    # -1 -> 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치


# 어떻게 풀까
    # 이차원 맵에서 모든 지점까지의 최단 거리를 구하는 문제이므로 BFS
    # 가까운 거리를 찾아야 하므로 출발점이 2인 곳부터 BFS를 시작하자?
        # for문으로 2인 지점을 찾자.
    # 2차원 맵이므로 dx, dy 상하좌우 활용해야 할 듯

    # 2인 지점을 start_x, y로 해놓고 뽑아서 상하좌우 탐색
    # 맵 안 범위이고, 아직 안 간 곳이면 append


from collections import deque

# 1. 입력값 파싱
height, width = map(int, input().split())

bfs_map = []
for _ in range(height):
    bfs_map.append(list(map(int, input().split())))

# 2. 출발점 2인 곳 찾기
for i in range(height):
    for j in range(width):
        if bfs_map[i][j] == 2:
            start_x = i
            start_y = j

# 3. 출력할 거리 초기화
distance = [[-1] * width for _ in range(height)]
distance[start_x][start_y] = 0 # -> 시작점은 거리 0이다.

# 4. 큐 만들기
q = deque()
q.append((start_x, start_y))

# dx, dy 정의 (상하좌우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

while q:
    # 조사 시이작
    x, y = q.popleft()

    for i in range(4):
        new_x = x + dx[i]
        new_y = y + dy[i]

        # 맵 범위인지 확인해서
        if 0 <= new_x < height and 0 <= new_y < width:
            # 갈 수 있고 안 간 곳이면~~
            if bfs_map[new_x][new_y] == 1 and distance[new_x][new_y] == -1:
                distance[new_x][new_y] = distance[x][y] + 1
                q.append((new_x, new_y))

# 5. 출력
for i in range(height):
    for j in range(width):
        if bfs_map[i][j] == 0:
            print(0, end=" ")
        else:
            print(distance[i][j], end=" ")
    print()

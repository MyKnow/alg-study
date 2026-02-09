import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

n, d = map(int, input().split()) # 지름길 개수, 고속도로 길이
graph = [[] for _ in range(d+1)] # 지름길 정보 저장
distances = [INF] * (d+1) # 최단거리 저장

for _ in range(n):
    start, end, distance = map(int, input().split()) # 시작 위치, 도착 위치, 지름길 길이
    graph[start].append((end, distance)) # start에서 end로 가는 가중치 distance

hq = []
heapq.heappush(hq, (0, graph[0][0])) # 시작노드 삽입...해야되는데 시작 노드가 뭐지... 여기서부터 막힘...
distances[graph[0][0]] = 0

while hq:
    cur_dist, cur = heapq.heappop() # 현재 위치, 거리 가져오기

    if cur_dist > distances[cur]: # 현재 거리가 저장된 최단 거리보다 크면 패스
        continue

    for i in graph[cur]: # 한 지점에 여러 지름길이 있을 수 있으므로 for문으로 모두 검사
        cost = cur_dist + i[1] # 다음 지점까지 거리 계산
        if cost < distances[i[0]]: # 다음 지점까지의 거리가 다음 지점보다 작으면
            distances[i[0]] = cost # 갱신
            heapq.heappush(hq, (cost, i[0]))

print(distances[d])

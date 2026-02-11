#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);

int N,D;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq[10005];
int d[10005];

int main() 
{
  cin>>N>>D;
  
  for (int i=0; i<D; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    pq[b].push({a,c}); // 도착지 기준, X는 출발지
  }
  
  // d[i] : i 까지 가기위한 최소값
  
  d[0] = 0;
  for (int i=1; i<=N; i++) {
    double ratio = 0;
    pair<int,int> min;
   
    // 다익스트라로 풀려다, 간선이 서로 끊어져서 상수값으로 연결해야 하는 부분에서 막히고
    // dp로 푸려다 막혔습니다
    
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
/*  
  priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 저장 형식은 int,int : 비용, 도착노드

  d[0] = 0; // 시작 노드의 비용 0 
  pq.push({ d[0], 0 });

  while (!pq.empty()) {
      auto cur = pq.top();  pq.pop(); // {비용, 정점 번호}

      // 꺼낸 cur 의 비용이 d 에 저장된 값과 다르면 continue
      if (cur.X != d[cur.Y]) continue;

      for (auto nxt : adj[cur.Y]) {
          if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; // 이미 최단 거리 테이블 값이 더 작으면 갱신 안해도 됨

          // nxt 노드를 거치는게 더 빠를 때
          d[nxt.Y] = d[cur.Y] + nxt.X; // d 테이블 갱신
          pq.push({ d[nxt.Y], nxt.Y }); // 갱신한 {비용, 정점 번호} 를 다시 우선순위 큐에 넣고, 또 검사
      }*/
  
  
  
  return 0;

}
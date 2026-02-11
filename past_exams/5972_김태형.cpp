//여물주는게 가중치네

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[50000];
vector<int> dist(50000,1e9);//초기값은 충분히 큰 값으로

void dijkstra(int start){
    //가장 맨 위에 작은 값이 있게 하려면 아래와 같이 우선순위큐를 선언해야함.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0,start});

    
    while(!pq.empty()){
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();


        if(dist[u] < here_cost) continue;

        for(auto there : adj[u]){
            int w = there.first;
            int v = there.second;
            
            if(here_cost + w < dist[v]){
                dist[v] = here_cost + w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    for(int i=0; i<m;i++){
        int u,v,w;
        cin >> v >> u >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    
    dijkstra(1); 
    cout << dist[n] << "\n";
    return 0;
}

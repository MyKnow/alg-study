#include<bits/stdc++.h>
using namespace std;
//최단거리니까 bfs 돌리자.
int N,M;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
//지도 맵
int arr[1001][1001];
//최단거리 나타낼 배열
int res[1001][1001];

void bfs(int sy, int sx){
    queue<pair<int, int>> q;

    q.push({sy,sy});
    res[sy][sx] = 0;
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4;i++){
            int ny = y +dy[i];
            int nx = x +dx[i];
            
            if(ny >= 0 && nx >= 0 && ny < N && nx < M){
                if(arr[ny][nx] == 1 && res[ny][nx] == -1){
                    res[ny][nx] = res[y][x] + 1;
                    q.push({ny,nx});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    //최단거리 나타낼 배열의 값을 전부 -1로 초기화
    fill(&res[0][0],&res[N][M],-1);

    int sy,sx;
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                sy = i;
                sx = j;
            }else if (arr[i][j] == 0){
                //못가는 곳은 방문배열로 막아야됨
                res[i][j] = 0;
            }
        }
    }

    bfs(sy,sx);

    for(int i=0; i<N;i++){
        for(int j=0;j<M;j++){
            cout  << res[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//불이 지나가는 bfs와 지훈이의 bfs를 둘이 분리해야되나?
//둘이 분리하면 먼저 bfs한거부터 끝나고 그 다음 bfs가 실행되니 불이 움직이지않고 지훈이가 혼자 움직이게될수 있어
//bfs를 합쳐서 생각해봐야겠다.

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
//불이 지나간 방문배열 / 지훈이가 지나간 방문배열
int f_visited[1004][1004], j_visited[1004][1004];
queue<pair<int,int>> q;
//지도 입력값
char arr[1004][1004];
//start jihun 좌표
vector<pair<int,int>> sj;
//start fire 좌표
vector<pair<int,int>> sf;
int R,C;

int bfs(){
    int sy = sj.back().first;
    int sx = sj.back().second;

    int fireY = sf.back().first;
    int fireX = sf.back().second;
    
    q.push({sy,sx});
    j_visited[sy][sx] = 1;
    f_visited[fireY][fireY] = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
    
        q.pop();
        for(int i=0; i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nfireY = fireY + dy[i];
            int nfireX = fireX + dx[i];
            //범위를 벗어날 경우 지훈이가 방문한곳을 반환한다.
            if(ny < 0 || nx < 0 || ny >= R || nx >= C) return j_visited[y][x];
            //다음 위치가 벽이거나, 불이거나, 불이 방문했던 자리는 못간다.
            if(arr[ny][nx] == '#' || arr[ny][nx] == 'F' || f_visited[ny][nx] != 0)continue;
            if(arr[ny][nx] == '.'){
                q.push({ny,nx});
                j_visited[ny][nx] = j_visited[y][x] + 1;
            }
            //불은 매초마다 상하좌우로 불이 붙는다.
            if(arr[ny][nx] != '#'){
                f_visited[nfireY][nfireX] = f_visited[fireY][fireX]; 
            }
            
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    string row[R];
    for(int i=0; i<R;i++){
        cin >> row[i];
    }
    for(int i=0; i<R;i++){
        for(int j=0; j<row[i].length();j++){
            if(row[i][j] == 'J') sj.push_back({i,j});
            if(row[i][j] == 'F') sf.push_back({i,j});
            arr[i][j] = row[i][j];
        }
    }

    int a = bfs();
    if(a == -1){
        cout << "IMPOSSIBLE";
    }else{
        cout << a;
    }
    
    
}

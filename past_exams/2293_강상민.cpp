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

int n, k;
int board[102];
int D[10002];


int main() {
    FIO;

    cin >> n >> k;
    for (int i = i; i <= n; i++) cin >> board[i];

    // D[i] = 가치가 i가 되도록 하는 경우의 수
    // D[1] = 1, D[2] = 2, D[3] = 2, D[4] = 3 ...


    // 1,2,3 의 가치가 있을 때 합 10 나타내는 가짓수
    // D[1] = 1, D[2] = 2, D[3] = 3, D[4] = 4,      D[2] : (1,1), (2)      D[3] : (1,1,1), (1,2),(3)  D[4] : (1,1,1,1), (1,1,2),(1,3),(2,2)
    // D[5] = 5 (1,1,1,1,1),(1,1,1,2),(1,1,3),(1,2,2),(2,3)
    // 항상 오름차순으로?
   

    // 만약 조합이 아닌 순열을 구하는 것이었으면 
    // 가치 1, 2, 5 일때
    // D[5] 같은건 D[4] + D[3] + D[0] 이런식으로 풀텐데..

    



    



   
    return 0;
}



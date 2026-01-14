#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &v,int h){
    int l =0;
    int r =v.size() -1;
    int res = 9999999;
    
    while(true){
        int mid = (v[l]+v[r])/2;
        int sum = 0;
        for(int i=0; i<v.size(); i++){
            sum += (v[i] - mid) >= 0 ? (v[i] - mid) : 0 ;
        }
        res = min(res,sum);
        if(res < h) mid--;
        if(res >= h) mid++;
    }
}
int n,m;

int main(){
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    
    cout << find(v, m) << "\n";

    return 0;
}


    //4 7
    //10 15 17 20

    //5 20
    //4 26 40 42 46

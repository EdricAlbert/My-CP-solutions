#include <bits/stdc++.h>

using namespace std;

const int maxN = 2*1e5;

struct info{
    int x;
    int w;
    int pos;
};

info coor[maxN+1];  
int n, m;

bool comparever1(const info& a, const info& b){
    return (a.w < b.w);
}

bool comparever2(const info& a, const info& b){
    return (a.x < b.x);
}

void readData(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> coor[i].x >> coor[i].w;
        coor[i].pos = i;
    }
    sort(coor+1,coor+1+m,comparever1);
}

void solve(){
    long long sum = 0;
    for (int i=1; i<=2*n; i++){
        sum+= coor[i].w;
    }
    cout << sum << '\n';
    sort(coor+1,coor+1+2*n,comparever2);
    for (int i=1; i<=n; i++){
        cout << coor[i].pos << " " << coor[2*n-i+1].pos;
        cout << '\n'; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--){
        readData();
        solve();
        cout << '\n';
    }
    return 0;
}
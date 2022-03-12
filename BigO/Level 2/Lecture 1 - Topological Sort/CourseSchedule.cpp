/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5+1;

int n, m;
bool flag;
vector<int> graph[maxN];
bool visited[maxN];
vector<int> q;
int check[maxN];

void readData(){
    cin >> n >> m;
    int x, y;
    for (int i=1; i<=m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }
    flag = true;
}

void topo(int u){
    visited[u] = true;
    check[u] = 1;
    for (int v : graph[u]){
        if (!visited[v])
            topo(v);
        if (check[v] == 1){
            flag = false;
            return;
        }
    }
    q.push_back(u);
    check[u] = 2;
}

void solve(){
    memset(visited,false,sizeof(visited));
    memset(check,0,sizeof(check));
    for (int i=1; i<=n; i++){
        if (!visited[i] && flag==true){
            topo(i);
        }
    }
    if (flag==false){
        cout << "IMPOSSIBLE";
    } else {
        for (int i = n -1; i>=0; i--){
            cout << q[i] << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    solve();
    return 0;
}
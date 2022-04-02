/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problem: 
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

int n, m;
vector<int> graph[maxN];
vector<bool> visited;
int res = 0;

void dfs(int u, int cnt){
    for (int v: graph[u]){
        if (!visited[v]){
            visited[v] = true;
            dfs(v, cnt+1);
            visited[v] = false;
        }
    }
    res = max(res, cnt);
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
        res = 0;
        cin >> n >> m;
        visited.assign(n+1, false);
        for (int i=1; i<=n; i++){
            graph[i].clear();
        }
        for (int u, v, i=1; i<=m; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        visited[1] = true;
        dfs(1, 1);
        if (res == n){
            cout << "Yes" << '\n';
        } else cout << "No" << '\n';
    }
}
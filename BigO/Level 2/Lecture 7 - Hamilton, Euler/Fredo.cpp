/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problem: 
**/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[100][100];    
int dist[1000];
vector<bool> visited;

void dfs(int u, int cnt){
    for (int i=1; i<=n; i++){
        if (!visited[i] && graph[u][i] == 1){
            visited[i] = true;
            dfs(i, cnt+1);
            visited[i] = false;
        }
    }
    dist[u] = max(dist[u], cnt);
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
        cin >> n >> m;
        memset(graph, 0, sizeof(graph));
        for (int u, v, i=1; i<=m; i++){
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        memset(dist, 0, sizeof(dist));
        for (int i=1; i<=n; i++){
            visited.assign(n+1, false);
            visited[i] = true;
            dfs(i, 0);
        }
        for (int i=1; i<=n; i++){
            cout << dist[i] << " ";
        }
        cout << '\n';
    }
}
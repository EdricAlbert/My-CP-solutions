#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
typedef pair<int,int> pii;
vector<int> dist, path;
vector<bool> visited;
vector<vector<pii>> adj;
int n,m;

bool prim(){
    dist.assign(n, INF);
    path.assign(n, -1);
    visited.assign(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, 0 });
    dist[0] = 0;
    int u,v,w;
    int count = 0;
    while (!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (visited[u]) continue;
        visited[u] = true;
        count++;
        for (pii nei: adj[u]){
            v = nei.first;
            w = nei.second;
            if (!visited[v] && dist[v]>w){
                dist[v] = w;
                path[v] = u;
                pq.push({ w, v });
            }
        }
    }
    return count == n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("MST.inp","r",stdin);
    freopen("MST.out","w",stdout);
    cin >> n >> m;  
    adj.assign(n, vector<pii>());
    for (int u, v, w, i = 0; i<m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    if (!prim()) cout << "Graph is not connect \n";
    else {
        int mst = 0;
        for (int i=0; i<n; i++){
            mst += dist[i];
        }
        cout << mst << '\n';
        for (int i=1; i<n; i++){
            cout << i << " " << path[i] << '\n';
        }
    }
    return 0;
}
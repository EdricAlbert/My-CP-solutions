#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

typedef pair<int , int> pii;
int dist[1000];
vector<bool> visited;

int n, m;
int a[1000][1000];
int value[1000][1000];

void prim(){
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    visited.assign(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = -INF;
    int u, v, w;
    while (!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        u = tmp.second;
        if (visited[u]) continue;
        visited[u] = true;
            for (int i=1; i<=n; i++){
            if (i==u) continue;
            v = i;
            w = value[u][i];
            int temp = dist[v];
            if (!visited[v] && dist[v]>w){
                dist[v] = w;
                pq.push({ w, v });
            }
        }
    }
    int kq = 0;
    for (int i=1; i<=n; i++){
        int temp = dist[i];
        if (dist[i] != -INF && dist[i] != INF){
            kq+= dist[i];
        }
    }
    cout << kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("NETWORK.inp","r",stdin);
    freopen("NETWORK.out","w",stdout);
    cin >> n >> m;
    int u,v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> value[i][j];
            if (a[i][j]==1 || a[j][i]==1){
                value[i][j] = -INF;
            }
        }
    }
    prim();
}
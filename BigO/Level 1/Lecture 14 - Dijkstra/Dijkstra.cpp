/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

typedef pair<long long, long long> pii;

vector<vector<pii>> graph;
vector<long long> dist, path;
int n, m;

void readData(){
    cin >> n >> m;
    graph.assign(n+5, vector<pii>());
    for (long long u, v, w, i=1; i<=m; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}

void dijkstra(long long s){
    dist.assign(n+1, INF);
    path.assign(n+1, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()){
        pii temp = pq.top();
        pq.pop();
        long long u = temp.second;
        if (temp.first != dist[u]) continue;
        for (long long i=0; i<graph[u].size(); i++){
            long long v = graph[u][i].first;
            long long w = graph[u][i].second;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push({dist[v], v});
            }
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
    dijkstra(1);
    if (dist[n]==INF){
        cout << -1;
    } else {
        long long v = n;
        vector<long long> res;
        while (v!=-1){
            res.push_back(v);
            v = path[v];
        }
        for (long long i = res.size() - 1; i>=0; i--){
            cout << res[i] << " ";
        }
    }
}
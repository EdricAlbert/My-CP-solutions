/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;
vector<vector<pii>> graph;
vector<pii> dist;

void readData(){
    cin >> n >> m;
    graph.assign(n+1, vector<pii>());
    for (int u, v, w, i=1; i<=m; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
}

void dijkstra(int u){
    dist.assign(n+1, {0, 0});
    priority_queue<pii, vector<pii>, greater<int>()> pq;
    pq.push({0,1});
    dist[1] = {0, 0};
    
    while (!pq.empty()){
        pii temp= pq.top();
        pq.pop();
        int u = temp.second;
        if (temp.first != dist[u].second) continue;
        for (int i=0; i<graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if 
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
    solve();
}
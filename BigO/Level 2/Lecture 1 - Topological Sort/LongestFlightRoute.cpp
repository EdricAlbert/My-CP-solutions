/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 10;

int n, m;
vector<int> graph[maxN];
int indegree[maxN];
int parent[maxN];
void readData(){
    cin >> n >> m;
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
}

void kahn(){ //O(V+E)
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (indegree[i] == 0 && i!=1) q.push(i);
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: graph[u]){
            indegree[v]--;
            if (indegree[v]==0){
                q.push(v);
            }
        }
    }
    q.push(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: graph[u]){
            indegree[v]--;
            if (indegree[v]==0){
                q.push(v);
                parent[v] = u;
            }
        }
    }
}

void solve(){
    parent[n] = -1;
    kahn();
    if (parent[n] == -1){
        cout << "IMPOSSIBLE";
    } else {
        vector<int> result;
        int v = n;
        while (v!=1){ //O(V)
            result.push_back(v);
            v = parent[v];
        }
        result.push_back(1);
        cout << result.size() << '\n';
        for (int i=result.size()-1; i>=0; i--){
            cout << result[i] << " ";
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
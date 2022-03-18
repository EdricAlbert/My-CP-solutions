/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

vector<int> graph[maxN];
vector<int> low, num, u, v;
vector<bool> visited;
int counter;
int numSCC;
int n, m;
stack<int> st;
int found[maxN];
int parent[maxN];

void dfs(int u){
    counter++;
    low[u] = num[u] = counter;
    st.push(u);
    for (int v: graph[u]){
        if (!visited[v]){
            if (num[v] > 0){
                low[u] = min(low[u], num[v]);
            } else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u]==low[u]){
        numSCC++;
        int v;
        do{
            v = st.top();
            found[v] = numSCC;
            visited[v] = true;
            st.pop();
        } while (v!=u);
    }
}

void tarjan(){
    visited.assign(n+1, false);
    low.assign(n+1, 0);
    num.assign(n+1, 0);
    counter = 0;
    numSCC = 0;
    st = stack<int>();
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dfs(i);
        }
    }
}

void createNewGraph(){
    for (int i=1; i<=numSCC; i++){
        graph[i].clear();
    }
    for (int i=0; i<m; i++){
        int x = found[u[i]];
        int y = found[v[i]];
        if (x!=y){
            graph[x].push_back(y);
        }
    }
}

void solve(){
    int result = 0;
    for (int i=1; i<=numSCC; i++){
        for (int v: graph[i]){
            parent[v]++;
        }
    }
    for (int i=1; i<=numSCC; i++){
        if (parent[i]==0){
            result++;
        }
    }
    cout << result << '\n';
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
        for (int i=1; i<=n; i++){
            graph[i].clear();
            found[i] = 0;
            parent[i] = 0;
        }
        u.clear();
        v.clear();
        for (int x, y, i=1; i<=m; i++){
            cin >> x >> y;
            u.push_back(x);
            v.push_back(y);
            graph[x].push_back(y);
        }
        tarjan();
        createNewGraph();
        solve();
    }
}
/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 805;

int n, m, counter, num_SCC;
vector<int> graph[maxN];
vector<int> low, num, u, v;
vector<bool> found;
stack<int> st;
int newGraph[maxN], inDegree[maxN];

void dfs(int u){
    counter++;
    low[u] = num[u] = counter;
    st.push(u);
    for (int v: graph[u]){
        if (!found[v]){
            if (num[v]>0){
                low[u] = min(num[v], low[u]);
            } else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u]==low[u]){
        num_SCC++;
        int v;
        do{
            v = st.top();
            newGraph[v] = num_SCC;
            found[v] = true;
            st.pop();
        } while(v!=u);
    }
}

void tarjan(){
    found.assign(n+1, false);
    low.assign(n+1, 0);
    num.assign(n+1, 0);
    counter = 0;
    num_SCC = 0;
    st = stack<int>();
    for (int i=1; i<=n; i++){
        if (!found[i]){
            dfs(i);
        }
    }
}

void solve(){
    int res = 0;
    for (int i=1; i<=num_SCC; i++){
        if (inDegree[i]==0) res++;
    }
    cout << res;
}

void make_graph(){
    for (int i=1; i<=num_SCC; i++){
        graph[i].clear();
    }
    for (int i=0; i<m; i++){
        int x = newGraph[u[i]];
        int y = newGraph[v[i]];
        if (x!=y){
            graph[x].push_back(y);
            inDegree[y]++;
        }
    }
}

void readData(){
    cin >> n >> m;
    for (int x, y, i=1; i<=m; i++){
        cin >> x >> y;
        u.push_back(x);
        v.push_back(y);
        graph[x].push_back(y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    tarjan();
    make_graph();
    solve();
}
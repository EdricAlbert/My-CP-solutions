/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5+1;

vector<int> graph[maxN],childinSCC[maxN];
vector<int> low, num, u, v, needtosorted;
vector<bool> visited;
stack<int> st;
int numSCC;
int found[maxN];
int n, m;
int counter;
int outDegree[maxN];

void readData(){
    cin >> n >> m;
    for (int x, y, i=1; i<=m; i++){
        cin >> x >> y;
        u.push_back(x);
        v.push_back(y);
        graph[x].push_back(y);
    }
}

void dfs(int u){
    counter++;
    low[u] = num[u] = counter;
    st.push(u);
    for (int v: graph[u]){
        if (!visited[v]){
            if (num[v]>0){
                low[u] = min(low[u],num[v]);
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
            childinSCC[numSCC].push_back(v);
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
    numSCC = 0 ;
    st = stack<int>();
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dfs(i);
        }
    }
}

void createGraphs(){
    for (int i=0; i<m; i++){
        int x = found[u[i]];
        int y = found[v[i]];
        if (x!=y){
            outDegree[x]++;
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
    tarjan();
    createGraphs();
    int chutrinh = 0;
    int result = 0;
    for (int i=1; i<=numSCC; i++){
        if (outDegree[i]==0){
            result++;
            chutrinh = i;
        }
    }
    if (result>1){
        cout << 0 << '\n';
    } else {
        for (int v: childinSCC[chutrinh]){
            needtosorted.push_back(v);
        }
        sort(needtosorted.begin(), needtosorted.end());
        cout << childinSCC[chutrinh].size() << '\n';
        for (auto x: needtosorted){
            cout << x << " ";
        }
    }
}
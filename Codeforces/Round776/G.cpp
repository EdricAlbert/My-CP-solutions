/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 2*1e5 + 1;
const long long needmod = 1e9 + 7;
int s,t,n,m;
long long res;  
vector<vector<int>> connect;
vector<int> path;
vector<bool> visited;

void dfs(int s){
    int sz = connect.size();
    path.assign(sz,-1);
    visited.assign(sz,false);
    stack<int> st;

    res = 0;

    st.push(s);
    visited[s] = true;

    int u,v;
    while (!st.empty()){
        u = st.top();
        st.pop();
        for (int i=0; i < connect[u].size(); i++){
            v = connect[u][i];
            if (!visited[v]){
                visited[v] = true;
                path[v] = u;
                st.push(v);
            }
            if (v == t) res++;
        }
    }
}

void solve(){
    dfs(s);
    cout << res % needmod << '\n';;
}

void readData(){
    cin >> n >> m;
    cin >> s >> t;
    int x,y;
    connect.assign(n+1, vector<int>());
    for (int i=1; i<=m; i++){
        cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
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
        readData();
        solve();
    }
}
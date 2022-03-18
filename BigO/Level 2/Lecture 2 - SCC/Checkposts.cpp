/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5+1;
const int modulo = 1e9 + 7;

vector<int> graph[maxN], mark[maxN];
vector<int> low, num;
vector<bool> found;
int cost[maxN];
int n, m;
int numSCC, counter;
stack<int> st;
long long r1, r2;

void readData(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> cost[i];
    }
    cin >> m;
    for (int u, v, i=1; i<=m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

void dfs(int u){
    counter++;
    low[u] = num[u] = counter;
    st.push(u);
    for (int v: graph[u]){
        if (!found[v]){
            if (num[v] > 0){
                low[u] = min(low[u], num[v]);
            } else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u]==num[u]){
        numSCC++;
        int v;
        do{
            v = st.top();
            found[v] = true;
            mark[numSCC].push_back(cost[v]);
            st.pop();
        } while (v!=u);
    }
}

void tarjan(){
    found.assign(n+1, false);
    low.assign(n+1, 0);
    num.assign(n+1, 0);
    counter = 0;
    numSCC = 0;
    st = stack<int>();
    for (int i=1; i<=n; i++){
        if (!found[i]){
            dfs(i);
        }
    }
}

void solve(){
    for (int i=1; i<=numSCC; i++){
        sort(mark[i].begin(),mark[i].end());
        int minimumcost = mark[i][0];
        int ways = 1;
        for (long long j=1; j<mark[i].size(); j++){
            if (minimumcost == mark[i][j]) ways++;
                else break;
        }
        r1 = r1 + minimumcost;
        r2 = r2 * ways % modulo;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    r1 = 0;
    r2 = 1;
    readData();
    tarjan();
    solve();
    cout << r1 << " " << r2;
}
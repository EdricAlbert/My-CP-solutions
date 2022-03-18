/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;


const int maxN = 5*1e5+1;
typedef pair<int, int> pii;
typedef long long ll;

vector<int> graph[maxN];
int n, m;
int numChild[maxN];
int counter, TPLT;
int num[maxN], low[maxN];
vector<pii> bridges;

void readData(){
    cin >> n >> m;
    for (int u, v, i=1; i<=n; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int u, int p){
    counter++;
    low[u] = num[u] = counter;
    numChild[u] = 1;
    for (int v: graph[u]){
        if (v==p) continue;
        if (num[v]){
            low[u] = min(low[u],num[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u],low[v]);
            numChild[u] += numChild[v];
            if (low[v] > num[u]){
                bridges.push_back(make_pair(u, v));
            } 
        }
    }
}

void tarjan(){
    counter = 0;
    TPLT = 0;
    for (int i=1; i<=n; i++){
        if (!num[i]){
            TPLT++;
            dfs(i, 0);
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
    if (TPLT >= 3){
        cout << 0;
    } else 
    if (TPLT == 2){
        long long ans = 1LL*(m-bridges.size())*1LL*numChild[1]*1LL*(n - numChild[1]);
        cout << ans << '\n';
    } else
    if (TPLT == 1){
        long long ans = 0;
        for(auto [u, v] : bridges){
            int minChild = min(numChild[u], numChild[v]);
            ans += 1LL*(n - minChild)*1LL*minChild - 1;
        }
         ans += 1LL*(m-bridges.size())*1LL*(1LL*n*(n-1)/2 - m);
        cout << ans;
    }
    return 0;
}
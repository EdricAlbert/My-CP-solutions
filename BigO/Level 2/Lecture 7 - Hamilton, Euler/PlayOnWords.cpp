/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problem: https://www.spoj.com/problems/WORDS1/
**/
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;
int n;

vector<bool> visited;
vector<int> graph[maxN];
vector<int> indegree, outdegree;

void dfs(int u){
    visited[u] = true;
    for (int v: graph[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    string st;
    cin >> t;
    while (t--){
        cin >> n;
        visited.assign(27, true);
        indegree.assign(27,0);
        outdegree.assign(27,0);
        for (int i=0; i<=26; i++) graph[i].clear();
        for (int i=1; i<=n; i++){
            cin >> st;
            int u = st[0] - 'a';
            int v = st[(st.size() - 1)] - 'a';
            graph[u].push_back(v);
            graph[v].push_back(u);
            visited[u] = true;
            visited[v] = false;
            indegree[v]++;
            outdegree[u]++;
        }
        int tplt = 0;
        for (int i=0; i<=26; i++){
            if (!visited[i]){
                dfs(i);
                tplt++;
            }
        }
        bool isEuler = true;
        if (tplt > 1){
            isEuler = false;
        }
        int tmp1 = 0;
        int tmp2 = 0;
        for (int i=0; i<=26; i++){
            if (abs(indegree[i]-outdegree[i]) > 1) isEuler = false;
            if (indegree[i] - outdegree[i] == 1){
                tmp1++;
            } 
            if (outdegree[i] - indegree[i] == 1){
                tmp2++;
            }
        }
        isEuler &= (tmp1 == 1 && tmp2 == 1) || (tmp1 == 0 && tmp2 == 0);
        if (isEuler){
            cout << "Ordering is possible." << '\n';
        } else {
            cout << "The door cannot be opened." << '\n';
        }
    }
}
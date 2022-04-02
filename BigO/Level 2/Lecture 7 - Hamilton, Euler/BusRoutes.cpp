/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problem: 
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 10000;

int n, m;
int deg[maxN][maxN];
vector<int> graph;
int in_degree[maxN], out_degree[maxN];
vector<bool> check(1001, false);
vector<int> connect[maxN];
vector<int> result;
int realm = 0;

void findEulerPath(int u){
    for (int v: connect[u]){
        if (deg[u][v]>0){
            deg[u][v]--;
            findEulerPath(v);
        }
    }
    result.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    for (int u, v, i=1; i<=n; i++){
        cin >> m;
        realm = realm + m;
        cin >> u;
        for (int i=1; i<=m; i++){
            cin >> v;
            deg[u][v] = 1;
            in_degree[v]++;
            out_degree[u]++;
            if (!check[u]) graph.push_back(u);
            if (!check[v]) graph.push_back(v);
            connect[u].push_back(v);
            check[u] = true;
            check[v] = true;
            u = v;
        }
    }
    int s1 = 0;
    int s2 = 0;
    int u = -1;
    int v = -1;
    bool isEuler = true;
    for (int i: graph){
        if (abs(in_degree[i] - out_degree[i])>=2){
            isEuler = false;
        }
        if (in_degree[i] - out_degree[i] == 1){
            s1++;
            u = i;
        }
        if (out_degree[i] - in_degree[i] == 1){
            s2++;
            v = i;
        }
    }
    if (u!=-1){
        deg[u][v] = 1;
        deg[v][u] = 1;
        connect[u].push_back(v);
        connect[v].push_back(u);
        realm++;
    }
    isEuler &= (s1==1 && s2==1) || (s1==0 && s2 == 0);
    if (isEuler){
        findEulerPath(graph[0]);
        int temp = result.size();
        if (result.size()!=realm+1){
            cout << 0 << '\n';
            return 0;
        }
        if (u!=-1){
            cout << realm-1 << " ";
            for (int i = result.size()-1; i>=0; i--){
                cout << result[i] << " ";
            }
            return 0;
        }
        for (int i = 0; i<result.size(); i++){
            if ((result[i]==u && result[i+1]==v) || result[i] == v && result[i+1] == u){
                for (int j=1; j<=i; j++){  
                    result.push_back(result[j]);
                }   
                result.erase(result.begin(), result.begin() + i + 1);
                break;
            }
        }
        cout << realm << " ";
        for (int i = result.size()-1; i>=0; i--){
            cout << result[i] << " ";
        }
    } else {
        cout << 0 << '\n';
    }
}
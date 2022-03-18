/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e5 + 5;

vector<int> graph[maxN];
int Node = 1;
int n, m;
vector<int> low, num;
vector<bool> found;
stack<int> st;
int counter;
int SCC;
vector<int> ans[maxN];
int ID;

void dfs(int u){
    counter++;
    low[u] = num[u] = counter;
    st.push(u);
    for (int v: graph[u]){
        if (!found[v]){
            if (num[v] > 0){
                low[u] = min(low[u],num[v]);
            } else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    int v;
    if (num[u]==low[u]){
        SCC++;
        do{
            v = st.top();
            found[v] = true;
            ans[SCC].push_back(v);
            st.pop();
        } while(v!=u);
    }
}

void tarjan(){
    low.assign(n+1, 0);
    num.assign(n+1, 0);
    found.assign(n+1, false);
    counter = 0;
    SCC = 0;
    for (int i=1; i<=n; i++){
        if (num[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    st = stack<int>();
    ID = 0;
    while (cin >> n >> m){
        ID++;
        if (n==m && m==0){
            break;
        }
        for (int i=0; i<=n; i++){
            graph[i].clear();
            ans[i].clear();
        }
        while (!st.empty()){
            st.pop();
        }
        string u, v;
        map <string,int> encode;
        map <int,string> decode;
        Node = 1;
        for (int i=1; i<=m; i++){
            cin >> u >> v;
            if (encode.find(u) == encode.end()){
                decode[Node] = u;
                encode[u] = Node++;
            } 
            if (encode.find(v) == encode.end()){
                decode[Node] = v;
                encode[v] = Node++;
            }
            graph[encode[u]].push_back(encode[v]);
        }
        tarjan();
        cout << "Calling circles for data set " << ID <<":" << '\n';
        for (int i=1; i<=SCC; i++){
            for (int j=0; j<ans[i].size(); j++){
                if (j != ans[i].size() - 1){
                    cout << decode[ans[i][j]] << ", ";
                } else {
                    cout << decode[ans[i][j]] << '\n';
                }
            }
        }
      	cout << '\n';
    }
}
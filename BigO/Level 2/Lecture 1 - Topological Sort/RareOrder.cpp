/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

string st;

const int maxN = 26;

vector<string> a;
bool visited[maxN];
vector<int> graph[maxN];
vector<int> q;

void readData(){
    memset(visited,true,sizeof(visited));
    while (cin >> st){
        if (st=="#") break;
        else {
            for (int i=0; i<st.size(); i++){
                visited[st[i]-'A'] = false;
            }
            a.push_back(st);
        }
    }
}

void topo(int u){
    visited[u] = true;
    for (char v: graph[u]){
        if (!visited[v]){
            topo(v);
        }
    }
    q.push_back(u);
}

void solve(){
    for (int i=0; i<a.size()-1; i++){
        for (int j=0; j<min(a[i].size(),a[i+1].size());j++){
            if (a[i][j]!=a[i+1][j]){
                graph[a[i+1][j]-'A'].push_back(a[i][j]-'A');
                break;
            }
        }
    }
    for (int i=1; i<=26; i++){
        if (!visited[i]){
            topo(i);
        }
    }
    for (int i=0; i<q.size()-1; i++){
        cout << char(q[i] + 'A');
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
}
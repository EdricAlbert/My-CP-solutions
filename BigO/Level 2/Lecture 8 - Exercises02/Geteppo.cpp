/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problem: 
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;
int a[1000][1000];
int n, m;
vector<int> res;
vector<bool> visited;
int result = 0;

void backtrack(int s){
    bool flag = true;
    if (s==n+1){
        for (int i=0; i<res.size(); i++){
            for (int j=0; j<res.size(); j++){
                if (a[res[i]][res[j]]==1){
                    flag = false;
                    break;
                }
            }
        }
        if (flag) result++;
        return;
    }
    for (int i=0; i<=1; i++){
        if (i==1){
            res.push_back(s);
        }
        backtrack(s+1);
        if (i==1) res.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int u, v, i=1; i<=m; i++){
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    res.clear();
    backtrack(1);
    cout << result;
}
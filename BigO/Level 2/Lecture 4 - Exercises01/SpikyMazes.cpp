/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxMaze = 25;

int n, m, k;
char a[maxMaze][maxMaze];
int mark1, mark2;
bool visited[maxMaze][maxMaze];
int td[8] = {0, 0, -1, 1};
int tc[8] = {1, -1, 0, 0};
int present;
bool res;

void readData(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            visited[i][j] = false;
            if (a[i][j] == '@'){
                mark1 = i;
                mark2 = j;
            }
        }
    }
}

bool check(int i, int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void dfs(int i, int j){
    visited[i][j] = true;
    if (res) return;
    if (a[i][j]=='s') {
        if (present<k) present++;
        else{
            visited[i][j] = false;
            return;
        }
    }
    if (a[i][j]=='x'){
        if (present==k){
            res = true;
            return;
        } else{
            visited[i][j] = false;
            return;
        }
    }
    for (int z = 0; z < 4; z++){
        int u = i + td[z];
        int v = j + tc[z];
        if (!visited[u][v] && a[u][v]!='#' && check(u, v)){
            dfs(u, v);
        }
    }
    visited[i][j] = false;
    if (a[i][j]=='s'){
        present--;
    }
}

void solve(){
    present = 0;
    res = false;
    dfs(mark1, mark2);
    if (res) cout << "SUCCESS";
        else 
    cout << "IMPOSSIBLE";
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
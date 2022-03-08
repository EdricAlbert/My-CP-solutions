#include <bits/stdc++.h>

using namespace std;
int a, b, c, n, m;
const int INF = 1e8;
vector<vector<int>> dtruck, dplane; 

void floydWarshall(vector<vector<int>>& truck, vector<vector<int>>& plane, int n){
    for (int k = 1; k<=n; k++){
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=n; j++){
                truck[i][j] = min(truck[i][j],truck[i][k]+truck[k][j]);
                plane[i][j] = min(plane[i][j],max(plane[i][k],plane[k][j]));
            }
        }
    } 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("TIEPTE.inp","r",stdin);
    freopen("TIEPTE.out","w",stdout);
    cin >> n >> m;
    cin >> a >> b >> c;
    vector<vector<int>> truck(n+1, vector<int>(n+1, INF));
    vector<vector<int>> plane(n+1, vector<int>(n+1, INF));
    int x, y, v, w;
    for (int i=1; i<=m; i++){
        cin >> x >> y >> v >> w;
        truck[x][y] = v;
        plane[x][y] = w;
    }
    floydWarshall(truck, plane, n);
    cout << truck[a][b]+truck[b][c] << '\n';
    cout << max(plane[a][b],plane[b][c]);
}
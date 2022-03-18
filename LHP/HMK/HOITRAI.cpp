#include <bits/stdc++.h>

#define inf 1e5
#define MAX 301

using namespace std;

long long n, m, k, table[MAX][MAX], dist[MAX][MAX], dem[MAX][MAX];

void floyd() {
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= n; ++ j) {
            dist[i][j] = table[i][j];
            dem[i][j] = 1;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dem[i][j] = dem[i][k]*dem[k][j];
                } else
                if (dist[i][j]==(dist[i][k]+dist[k][j])){
                    dem[i][j] += dem[i][k]*dem[k][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("HOITRAI.INP", "r", stdin);
    freopen("HOITRAI.OUT", "w", stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            table[i][j] = inf;
        }
    }
    for(int i = 1; i <= m; ++ i) {
        int x, y;
        cin >> x >> y;
        table[x][y] = 1;
        table[y][x] = 1;
    }
    floyd();
    for(int i = 1; i <= k; ++ i) {
        int x, y;
        cin >> x >> y;
        cout << dem[x][y] << '\n';
    }
    return 0;

}
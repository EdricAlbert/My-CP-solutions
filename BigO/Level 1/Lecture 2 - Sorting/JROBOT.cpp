#include <bits/stdc++.h>

using namespace std;

int a[1001][1001],b[1000002];
bool check[20000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,n,dem;
    dem = 0;
    cin >> m >> n;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
            if (check[a[i][j]]==false){
                dem++;
                b[dem]=a[i][j];
                check[a[i][j]]=true;
            }
        }
    }
    int x,y;
    cin >> x >> y;
    sort(b+1,b+dem+1);
    for (int i=1; i<=dem; i++){
        if (b[i]==a[x][y]){
            cout << (dem-i);
            break;
        }
    }
    return 0;
}
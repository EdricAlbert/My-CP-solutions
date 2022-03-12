#include <bits/stdc++.h>

using namespace std;
int m,n,t;
char a[100][100];

bool check(int x, int y){
    return(a[x][y+1]=='#' && a[x+1][y] == '#' && a[x+1][y+1]=='#');
}

int main(){
    cin >> t;
    for (int tc=1; tc<=t; tc++){
        cin >> m >> n;
        memset(a,0,sizeof(a));
        bool kt=true;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                cin >> a[i][j];
            }
        }
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (a[i][j]=='#'){
                    if (check(i,j)==true){
                        a[i][j] = '/';
                        a[i][j+1] = '\\';
                        a[i+1][j] = '\\';
                        a[i+1][j+1] = '/';
                    } else {
                        kt=false;
                        break;
                    }
                }
            }
        }
        if (kt==false){
            cout << "Case #" << tc << ": " << '\n' << "Impossible" << '\n';
        } else {
            cout << "Case #" << tc << ": " << '\n';
            for (int i=1; i<=m; i++){
                for (int j=1; j<=n; j++){
                    cout<<a[i][j];
                }
                cout << '\n';
            }
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
typedef pair<int , int> pii;
const int maxN = 510;

int n,m;
int a[maxN][maxN];
int checkcol[maxN];

bool readData(){
    int temp = 0;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            checkcol[i] = 1;
        }
    temp ^= a[i][1];
    }
    if (temp>0){
        cout << "TAK \n";
        for (int i=1; i<=n; i++){
            cout << "1" << " ";
        }
        return true;
    }
    return false;
}

void solve(){
    int temp = 0;
    for (int i=1; i<=n; i++){
        for (int j=2; j<=m; j++){
            if (a[i][1] != a[i][j]){
                checkcol[i] = j;
                cout << "TAK \n";
                temp = a[i][1] ^ a[i][j];
                for (int i=1; i<=n; i++){
                    cout << checkcol[i] << " ";
                }
                return;
            }
        }
    }
    if (temp == 0){
        cout << "NIE";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    if (!readData()){
        solve();
    }
    return 0;
}
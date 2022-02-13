#include <bits/stdc++.h>

using namespace std;

vector<long long> res(250000);
int a[502][502],m,n,k;
int tc[8] = {-1,-1,-1,0,0,1,1,1};
int td[8] = {-1,0,1,-1,1,-1,0,1};
void solve(){
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            long long x=0;
            for (int z=0; z<8; z++){
                x += (long long)a[i+td[z]][j+tc[z]];
            }
            res.push_back(x);
        }
    }
    sort(res.begin(),res.end());
}

void readData(){
    memset(a,0,sizeof(a));
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    solve();
    int example;
    vector<long long>::iterator v1,v2;
    for (int i=1; i<=k; i++){
        cin >> example;
        v1 = lower_bound(res.begin(),res.end(),example);
        v2 = upper_bound(res.begin(),res.end(),example);
        if (v2-v1>0) cout << 1 << " ";
            else
        cout << 0 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("CITY.inp","r",stdin);
    readData();
    return 0;
}
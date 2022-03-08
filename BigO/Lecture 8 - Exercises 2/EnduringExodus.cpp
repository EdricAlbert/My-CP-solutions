#include <bits/stdc++.h>

using namespace std;
int v[100001],dem,n,k;
char st[100001];
void readData(){
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> st[i];
        if (st[i]=='0'){
            dem++;
            v[dem] = i;
        }
    }
}

void solve(){
    int res=200000;
    for (int i=1; i<=dem; i++){
        if (i+k>dem) break;
        for (int j=i+1; j<=i+k; j++){
            res = min(res,max(v[j]-v[i],v[i+k]-v[j]));
            if (min(v[j]-v[i],v[i+k]-v[j])>=((v[i+k]-v[i])/2)+1) break;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.inp","r",stdin);
    readData();
    solve();
    return 0;
}
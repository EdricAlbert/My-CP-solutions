#include <bits/stdc++.h>

using namespace std;

long long k;

long long tinh (long long& x){
    long long dem=0;
    for (long long i=1; i<sqrt(x); i++){
        dem += (long long) sqrt(x-i*i);
    }
    return dem;
}

void solve(){
    long long r = 1e12;
    long long l = 0;
    long long res;
    long long mid;
    while (l<=r){
        mid = (l+r)/2;
        if (tinh(mid)>=k){
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res;
}

void readData(){
    int ID;
    cin >> ID >> k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("BINHPHUONG.inp","r",stdin);
    readData();
    solve();
    return 0;
}

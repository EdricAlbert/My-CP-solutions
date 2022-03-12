#include <bits/stdc++.h>

using namespace std;

long long k, n;

void readData(){
    cin >> n >> k;
}

void solve(){
    long long res = 0;
    if (k==1){
        cout << n;
    } else {
        while (n>0){
            n = n>>1;            
            res = res << 1 | 1;
        }
        cout << res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    solve();
    return 0;
}
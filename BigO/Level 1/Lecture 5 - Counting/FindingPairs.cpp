#include <bits/stdc++.h>

using namespace std;

int d[1000000],c[1000000];

int solve(){
    int n;
    cin >> n;
    int res=0;
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        if (x>0){
            d[x]++;
            res+=d[x];
        } else{
            c[abs(x)]++;
            res += c[abs(x)];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.inp","r",stdin);
    int testcases;
    cin >> testcases;
    for (int i=1; i<=testcases; i++){
        memset(d,0,sizeof(d));
        memset(c,0,sizeof(c));
        cout << solve() << '\n';
    }
    return 0;
}

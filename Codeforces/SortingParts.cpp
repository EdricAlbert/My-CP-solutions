#include <bits/stdc++.h>

using namespace std;
int n,a[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> n;
        bool kt = true;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            if (a[i]<a[i-1]) kt=false;
        }
        if (kt==false) cout << "YES" << '\n';
            else cout << "NO" << '\n';
    }
    return 0;
}
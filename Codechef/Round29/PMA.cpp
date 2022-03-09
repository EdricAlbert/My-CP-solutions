/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;
long long x;
long long t, n, maxnum, minnum, res;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;
    while (t--){
        cin >> n;
        minnum = 1e9+1;
        maxnum = 0;
        res = 0;
        for (int i=1; i<=n; i++){
            cin >> x;
            x = abs(x);
            if (i%2==1){
                minnum = min(minnum, x);
                res = res + x;
            } else {
                maxnum = max(maxnum, x);
                res = res - x;
            }
        }
        if (maxnum >= minnum) 
            res = res + 2*maxnum - 2*minnum;
        cout << res << '\n';
    }
}
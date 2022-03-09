/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t, n, x;
    cin >> t;
    while (t--){
        cin >> n >> x;
        int res = 0;
        int temp;
        for (int i=1; i<=n; i++){
            cin >> temp;
            if (temp < x){
                res = i;
            }
        }
        cout << res << '\n';
    }
}
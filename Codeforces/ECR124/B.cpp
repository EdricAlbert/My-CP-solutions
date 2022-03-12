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
    int t;
    cin >> t;
    int n;
    while (t--){
        cin >> n;
        if (n>19) cout << "NO" << '\n';
            else
        {
            cout << "YES" << '\n';
            int res = 1;
            cout << res << " ";
            for (int i=2; i<=n; i++){
                res = res * 3;
                cout << res << " "; 
            }
            cout << '\n';
        }
    }
}
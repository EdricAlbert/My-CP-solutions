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
        if (n%2==0){
            cout << n/2 << '\n';
        } else {
            cout << n/2 + 1 << '\n';
        }
    }
}
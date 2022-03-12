/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

int a[30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    a[0] = 1;
    for (int i=1; i<=30; i++){
        a[i] = a[i-1]*2;
    }
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        cout << a[x]-1 << '\n';
    }
}
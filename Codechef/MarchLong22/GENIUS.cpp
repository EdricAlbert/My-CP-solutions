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
    int n, s;
    while (t--){
        int a, b;
        cin >> n >> s;
        if (s%3>0){
            a = s/3 + 1;
        } else {
            a = s/3;
        }
        b = a*3 - s;
        if (a+b>n){
            cout << "NO" << '\n';
        } else {
            cout << a << " " << b << " 0" << '\n';
        }
    }
}
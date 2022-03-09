#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t, l, r, a;
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> l >> r >> a;
        if ( (r - l + 1) >= a ){
            int maxrange = (r - (a-1))/a;
            int temp = a-1 + maxrange * a;
            cout << temp/a + temp%a << '\n';
        } 
        else {
            if ( (a - 1 - l%a) <= (r - l) ){
                int maxrange = (r - (a-1))/a;
                int temp = a-1 + maxrange * a;
                cout << temp/a + temp%a << '\n';
            } else {
                cout << r/a + r%a << '\n';
            }
        }
    }
}
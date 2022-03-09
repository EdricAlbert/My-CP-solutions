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
    int t, n;
    string st;
    cin >> t;
    for (int j=1; j<=t; j++){
        cin >> n;
        cin >> st;
        st = st + "0";
        int i = 0;
        int res = 0;
        while (i<n){
            if (st[i] == st[i+1]){
                res++;
                i+=2;
            } else {
                res++;
                i+=1;
            }
        }
        cout << res << '\n';
    }
}
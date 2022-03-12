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
    long long n;
    cin >> t;
    while(t--){
        cin >> n;
        int temp = n/7;
        cout << temp + n%7/6 << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long n;
    cin >> n;
    if (n == 1) cout << 0;
        else
    if (n%2==1) cout << n/2;
        else
    cout << n/2 - 1;
    return 0;
}
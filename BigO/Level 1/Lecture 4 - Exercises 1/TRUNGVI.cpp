#include <bits/stdc++.h>

using namespace std;

int b[100],a[100];
int n;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[j];
        }
        sort(a+1, a+n+1);
        b[i] = a[n/2+1];
    }
    sort(b+1, b+1+n);
    cout << b[n/2+1];
}

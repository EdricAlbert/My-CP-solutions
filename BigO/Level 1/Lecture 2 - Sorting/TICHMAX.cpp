#include <bits/stdc++.h>

using namespace std;

int n;
long long a[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    long long tich1=1;
    sort(a,a+n);
    for (int i=1; i<n; i++){
        if (a[i]<0 && a[i-1]<0){
            tich1 = a[i-1]*a[i]*a[n-1];
            break;
        }
    }
    long long tich2 = a[n-2]*a[n-3]*a[n-1];
    cout << max(tich1,tich2);
}

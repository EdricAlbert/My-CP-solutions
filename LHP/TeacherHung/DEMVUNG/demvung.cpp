#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
    if (n==1 || n==0) return 1;
    else
        return n * factorial(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("demvung.inp","r",stdin);
    freopen("demvung.out","w",stdout);
    int t, n;
    cin >> t;
    double kq;
    for (int i=1; i<=t; i++){
        kq = 0;
        cin >> n;
        if (n==1) cout << 1 << '\n';
            else
        if (n==2) cout << 2 << '\n';
            else
        if (n==3) cout << 4 << '\n';
            else 
        {
            kq = (double)(n-1)/2;
            kq = (double)n*kq + 1;
            long long a = factorial(4);
            long long b = factorial(n);
            long long c = factorial(n-4);
            long long temp = (double)b/(a*c);
            kq += temp;
            cout << kq << '\n';
        }
    }
}
#include <bits/stdc++.h>

using namespace std;
int a[100000];
double res;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,l;
    cin >> n >> l;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    res=0;
    sort(a,a+n);
    for (int i=0; i<n-1; i++){
        res = max(res,double((a[i+1]-a[i]))/2);
    }
    res = max(res,double((l-a[n-1])));
    res = max(res,double((a[0]-0)));
    printf("%.2f",res);
}

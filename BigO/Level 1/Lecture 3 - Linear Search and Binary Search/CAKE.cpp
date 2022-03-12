#include <bits/stdc++.h>

using namespace std;

int res,n;
int a[1000001];

void readData(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
}

void bs(int left, int right){
    while (left<=right){
        int mid = (left+right)/2;
        bool kt=true;
        for (int i=1; i<=mid; i++){
            if (a[mid-i+1]*2>a[n-i+1]){
                kt = false;
            }
        }
        if (kt){
            res = mid;
            left = mid+1;
        }
            else
                right = mid-1;
    }
}

void solve(){
    bs(1,n/2);
    cout << res + (n-res*2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.inp","r",stdin);
    readData();
    solve();
    return 0;
}
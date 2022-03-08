#include <bits/stdc++.h>

using namespace std;

int n,res;
int a[200000];
void solve(){
    res=0;
    int l = 0;
    int r = 0;
    while(l<n){
        if (a[l]-5<=a[r] && r<n) r++;
            else{
                res = max(res,(r-1)-l+1);
                l++;
            }
    }
    cout << res;
}

void readData(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n,greater<int>());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    solve();
}
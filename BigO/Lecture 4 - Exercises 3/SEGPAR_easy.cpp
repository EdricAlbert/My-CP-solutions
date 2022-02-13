#include <bits/stdc++.h>

using namespace std;

int a[15000];
int k,n,l,r,res;

int check(int x){
    int tg=0;
    int kq=0;
    for (int i=1; i<=n; i++){
        if (tg+a[i]>x){
            kq++;
            tg = 0;
        }
        tg+=a[i];
    }
    return kq+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("text.inp","r",stdin);
    cin >> n >> k;
    int tg=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        r += a[i];
        l = max(l,a[i]);
    }
    while (l<=r) {
        int mid = (l+r)/2;
        int temp = check(mid);
        if (temp==k || temp<k){
            res = mid;
            r = mid - 1;
        } else {
            l = mid+1;
        }
    }
    cout << res;
}
    
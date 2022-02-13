#include <bits/stdc++.h>
using namespace std;

struct SanPham{
    int hop;
    int vienbi;
};

int n,m,res;
SanPham a[1001];

bool compare(SanPham x, SanPham y){
    if (x.vienbi < y.vienbi){
        return 0;
    } else {
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("MUABI.inp","r",stdin);
    //freopen("MUABI.out","w",stdout);
    cin >> n >> m;
    for (int i=0 ; i<m; i++){
        cin >> a[i].hop >> a[i].vienbi;
    }
    sort(a,a+m,compare);
    for (int i=0; i<m; i++){
        if (n>a[i].hop){
            res = res + a[i].hop*a[i].vienbi;
            n = n - a[i].hop;
        } else {
            res = res + a[i].vienbi*n;
            break;
        }
    }
    cout << res;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
string st;
int cnt[2002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    cin >> st;
    st = st + st;
    int hamster = 0;
    for (int i=0; i<2*n; i++){
        if (st[i] == 'H'){
            hamster++;
            cnt[i] = cnt[i-1];
        } else 
        if (st[i] == 'T'){
            cnt[i] = cnt[i-1] + 1;
        } else {
            cnt[i] = cnt[i-1];
        }
    }
    hamster = hamster/2;
    int res = cnt[hamster - 1];
    for (int i = 1; i<2*n - hamster - 1; i++){
        res = min(res, cnt[i + hamster - 1] - cnt[i - 1]);
    }
    cout << res;
}
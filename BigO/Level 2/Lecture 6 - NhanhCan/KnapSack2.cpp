/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problem: https://atcoder.jp/contests/dp/tasks/dp_e
**/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int w[90], v[90];
int res = -1e9;

void backtrack(int index, int sumw, int sumv){
    if (index==n+1){
        return;
    }
    for (int i = index; i<=n; i++){
        if (sumw + w[i] <= k){
            backtrack(i+1, sumw + w[i], sumv + v[i]);
            res = max(res, sumv + v[i]);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    backtrack(1,0, 0);
    cout << res;
}
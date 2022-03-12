#include <bits/stdc++.h>

using namespace std;

const int maxN = 3*1e5;
const int maxNN = 1<<21;

int n;
int sumXor[2][maxNN];
int tmp = 0;
long long res = 0;

void solve(){
    memset(sumXor,0,sizeof(sumXor));
    sumXor[0][0] = 1;
    cin >> n;
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        tmp = tmp ^ x;
        res += sumXor[i%2][tmp];
        sumXor[i%2][tmp]++;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
}
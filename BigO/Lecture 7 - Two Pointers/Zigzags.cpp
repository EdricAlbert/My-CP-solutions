#include <bits/stdc++.h>

using namespace std;

int n;
int a[3001];
int cntr[3001],cntl[3001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        long long ans = 0;
        memset(cntl,0,sizeof(cntl));
        for (int pointer1 = 1; pointer1 <= n; pointer1++){
            memset(cntr,0,sizeof(cntr));
            for (int pointer2 = n; pointer2 >= pointer1+1; pointer2--){
                ans += cntr[a[pointer1]]*cntl[a[pointer2]];
                cntr[a[pointer2]]++;
            }
            cntl[a[pointer1]]++;
        }
        cout << ans << '\n';
    
    }
}
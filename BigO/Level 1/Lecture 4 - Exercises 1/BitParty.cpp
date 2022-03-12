#include <bits/stdc++.h>

using namespace std;

long long maxS, maxP;
long long m[1003], s[1003], p[1003];
int R,B,C;

void readData(){
    maxS = 0;
    maxP = 0;
    cin >> R >> B >> C;
    for (int i=1; i<=C; i++){
        cin >> m[i] >> s[i] >> p[i];
        maxS = max(maxS,s[i]);
        maxP = max(maxP,p[i]);
    }
}

bool check(long long x){
    long long capa[1003];
    long long sum = 0;
    for (int i = 1; i<=C; i++){
        capa[i] = max(0ll,min((long long)m[i],(long long)floor((long double)(x - p[i])/s[i])));
    }
    sort(capa+1,capa+1+C, greater<long long>());
    for (int i=1; i<=R; i++){
        sum += 1ll*capa[i];
    }
    return (sum>=B);
}

void solve(){
    long long left = 0;
    long long res;
    long long right = 1ll*maxS*B + maxP;
    while (left <= right){
        long long mid = (left+right)/2;
        if (check(mid)){
            right = mid - 1;
            res = mid;
        }   else {
            left = mid + 1;
        }
    }
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int testcases;
    cin >> testcases;
    for (int i=1; i<=testcases; i++){
        cout << "Case #" << i << ": ";
        readData();
        solve();
    }
}
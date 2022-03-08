#include <bits/stdc++.h>
using namespace std;

long long r,t;

void readData(){
    cin >> r >> t;
}

long long check(long long x){
    return(2*r + 2*x - 1);
}

long long solve(){
    
}

long long solve(){
    long long res = 0;
    long long left = 0;
    long long right = t;
    while (left<=right){
        long long mid = (left+right)/2;
        if (mid==0) return 0;
        if (check(mid)<=(t/mid)){
            res = mid;
            left = 1 + mid;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases;
    cin >> testcases;
    for (int test=1; test<=testcases; test++){
        cout << "Case #" << test<<": ";
        readData();
        cout << solve() << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxN = 3*1e5 + 1;

int n, m;
long long sumA, sumB;
int a[maxN], b[maxN];

void readData(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        sumA += a[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        cin >> b[i];
        sumB += b[i];
    }
}

void solve(){
    if (sumA!=sumB){
        cout << -1;
        return;
    }
    sumA = a[1];
    sumB = b[1];
    int pointerA = 1;
    int pointerB = 1;
    int res = 0;
    while (pointerA <= n && pointerB <= m){
        if (sumA == sumB){
            pointerA++;
            pointerB++;
            sumA = a[pointerA];
            sumB = b[pointerB];
            res++;
        } else 
        if (sumA > sumB){
            pointerB++;
            sumB += b[pointerB];
        } else {
            pointerA++;
            sumA += a[pointerA];
        }
    }
    if (pointerA != (n + 1) || pointerB != (m + 1)){
        cout << -1; return;
    }
    cout << res;
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
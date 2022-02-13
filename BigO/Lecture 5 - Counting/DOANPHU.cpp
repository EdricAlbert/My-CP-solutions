#include <bits/stdc++.h>

using namespace std;

    int dem1[1000],dem2[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int largest = 0;
    int res = 0;
    int x,y;
    for (int i=1; i<=n; i++){
        cin >> x >> y;
        if (x>y) swap(x,y);
        for (int j=x+1; j<=y; j++){
            dem1[j]++;
        }
        largest = max(largest,y);
    }
    for (int i=1; i<=largest; i++){
        dem2[dem1[i]]++;
        res = max(res,dem1[i]);
    }
    cout << dem2[res];
}

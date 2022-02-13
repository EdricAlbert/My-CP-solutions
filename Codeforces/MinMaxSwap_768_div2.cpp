#include <bits/stdc++.h>

using namespace std;

int a[101];
int b[101];
int maxnum = 0, kt=0;
int n;

void readData(){
    cin >> n;
    maxnum = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i]>maxnum){
            maxnum = a[i];
            kt = 1;
        }
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        if (b[i]>maxnum){
            maxnum = b[i];
            kt = 2;
        }
    }
}


long long solve(){
    int maxothers = 0;
    if (kt==1){
        for (int i=1; i<=n; i++){
            if (a[i]<b[i]){
                int o = a[i];
                a[i] = b[i];
                b[i] = o;   
            }
            maxothers = max(maxothers, b[i]);
        }
    } else {
        for (int i=1; i<=n; i++){
            if (a[i]>b[i]){
                int o = a[i];
                a[i] = b[i];
                b[i] = o;
            }
            maxothers = max(maxothers, a[i]);
        }
    }
    return(maxnum*maxothers);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        readData();
        cout << solve() << '\n';
    }
    return 0;
}
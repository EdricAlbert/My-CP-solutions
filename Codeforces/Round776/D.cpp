    #include <bits/stdc++.h>

    using namespace std;

    const int maxN = 2*1e3;

    int n;
    int a[maxN+1], change[maxN+2];

    void readData(){
        cin >> n;
        int x;
        for (int i=1; i<=n; i++){
            cin >> x;
            a[x] = i;
        }
    }

    void solve(){
        for (int i=n; i>1; i--){
            if (a[i] >= i){
                change[i] = a[i] - i;
                a[i] = i;
            } else {
                change[i] = a[i];
                a[i] = i;
            }
            for (int j = i - 1; j>1; j--){
                if (change[i] >= a[j]){
                    a[j] = i - (abs(change[i] - a[j]))%i;
                } else {
                    a[j] = a[j] - change[i];
                }
            }
        }
        for (int i=1; i<=n; i++){
            cout << change[i] << " ";
        }
        cout << '\n';
    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int t;
        cin >> t;
        for (int i=1; i<=t; i++){
            readData();
            solve();
        }
        return 0;
    }
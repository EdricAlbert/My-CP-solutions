    #include <bits/stdc++.h>

    using namespace std;

    int n;
    long long a[200002];

    void readData(){     
        cin >> n;
        memset(a,0,sizeof(a));
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
    }

    int solve(){
        int temp1 = 1;
        int temp2 = 1;
        int kq = 0;
        for (int i=n-1; i>=1; i--){
            if (a[i]!=a[n]){
                if (temp1>temp2){
                    temp2++;
                } else {
                    kq++;
                    temp1 *=2;
                    temp2++;
                }
            } else{
                if (temp1>temp2){
                    temp2++;
                }
                else {  
                    temp1++;
                    temp2++;
                }
            }
        }
        return kq;
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
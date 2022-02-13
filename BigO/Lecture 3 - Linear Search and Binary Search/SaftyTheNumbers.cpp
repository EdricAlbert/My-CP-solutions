    #include <bits/stdc++.h>

    using namespace std;

    long long sum;
    int s[201], n;

    void readData(){
        sum = 0;
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> s[i];
            sum+= s[i];
        }
    }

    bool check(double mid, int i){
        double FinalScore = s[i] + sum*mid;
        double countt = mid;
        for (int j=1; j<=n; j++){
            if (j==i) continue;
            countt += (double)max(0.0,(FinalScore - s[j]))/sum;
        }
        return (countt>=1);
    }

    double find (int i){
        double left = 0.0;
        double right = 1.0;
        int need_to_check = i;
        for (int j=1; j<=100; j++){
            double mid = (left+right)/2.0;
            if (check(mid, need_to_check)){
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    void solve(){
        for (int i=1; i<=n; i++){
            double percentage = find(i);
            cout << fixed << setprecision(6) << percentage*100 << " ";
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
            cout << "Case #" << i << ": ";
            solve();
        }
        return 0;
    }
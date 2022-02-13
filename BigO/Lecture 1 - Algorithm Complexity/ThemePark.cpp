#include <bits/stdc++.h>

using namespace std;

long long R,k,n;
vector<int> a, finish;
vector<long long> total;
long long ans;

void readData(){
    cin >> R >> k >> n;
    long long x;
    a.clear();
    for (int i=1; i<=n; i++){
        cin >> x;
        a.push_back(x);
    }
}

void findGroups(){
    for (int i=0; i<n; i++){
        a.push_back(a[i]);
    }
    long long sum = 0;
    total.clear();
    finish.clear();
    for (int i = 0; i<n; i++){
        int j = i;
        while (j - i + 1 <= n && sum + a[j] <=k){
            sum+=a[j];
            j++;
        }
        total.push_back(sum);
        finish.push_back((j-1)%n);
        sum = 0;
    }
}

void calculate(){
    bool kt = false;
    long long h[2000];
    int check[2000];
    int peek[2000];
    memset(h,0,sizeof(h));
    memset(peek,-1,sizeof(peek));
    memset(check,0,sizeof(check));
    int i = 0;
    int j = 0;
    long long temp;
    while (kt==false){
        if (peek[finish[i]]==-1 || peek[finish[i]]!=i){
            j++;
            if (check[i]==0) check[i] = j-1;
            h[j] = h[j-1] + total[i];
            peek[finish[i]] = i;
            i = (finish[i] + 1)%n;
        } else {
            if (R<=j){
                ans = h[R];
                break;
            } else {
                if (i==0){
                    temp = 0;
                    ans = 0;
                }
                else{
                    temp = h[check[i]];
                    ans = h[check[i]];
                }
                long long cycle = h[j] - ans;
                ans += cycle*((R-check[i])/(j-check[i]));
                R = (R-check[i])%(j-check[i]);
                ans = ans + h[R+check[i]]-temp;
                break;
            }
        }
    }
}

long long solve(){
    findGroups();
    calculate();
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        readData();
        if (n==1){
            cout << "Case #" << t << ": " << a[0]*R << '\n';
        } else {
            cout << "Case #" << t << ": " << solve() << '\n';
        }
    }
    return 0;
}
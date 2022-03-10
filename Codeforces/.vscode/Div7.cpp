#include <bits/stdc++.h>

using namespace std;

int n;

void readData(){
    cin >> n;
}

string solve(){
    int minmin = 4;
    string result;
    if (n%7==0) return to_string(n);
    string tempa = to_string(n);
    for (int i=1; i<=142; i++){
        int x = i*7;
        string tempb = to_string(x);
        if (tempa.size()!=tempb.size()) continue;
        int compare = 0;
        for (int j=0; j<tempa.size(); j++){
            if (tempa[j]!=tempb[j]) compare++;
        }
        if (compare < minmin){
            minmin = compare;
            result = tempb;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while (T--){
        readData();
        cout << solve() << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string st;

void readData(){
    cin >> st;
}

int solve(){
    int maxnum = 0;
    int dem1[200000];
    int dem0[200000];
    for (int i=0; i<st.length(); i++){
        if (int(st[i])==49){
            dem1[i+1] = dem1[i] + 1;
            dem0[i+1] = dem0[i];
        } else {
            dem1[i+1] = dem1[i];
            dem0[i+1] = dem0[i]+1;
        }
        if (dem1[i+1]>dem0[i+1]) maxnum = max(maxnum,dem0[i+1]);
            else 
        if (dem0[i+1]>dem1[i+1]) maxnum = max(maxnum,dem1[i+1]);
    }
    return maxnum;
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
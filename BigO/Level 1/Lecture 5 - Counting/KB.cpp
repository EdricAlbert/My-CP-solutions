#include <bits/stdc++.h>

using namespace std;

int n,res;
string st;
int dem[2000];

void readData(){
    cin >> n;
    cin >> st;
}

int solve(){
    res=0;
    if (n>26) return -1;
    for (int i=0; i<n; i++){
        dem[st[i]]++;
    }
    for (char i = 'a'; i<='z'; i++){
        if (dem[i]!=0) res += dem[i]-1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    readData();
    cout << solve();
}

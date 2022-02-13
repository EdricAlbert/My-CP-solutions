#include <bits/stdc++.h>
using namespace std;

string st;
int length, k;

void readData(){
    cin >> length >> k;
    cin >> st;
}

int solve(){
    bool kt = true;
    for (int i=0; i<=(length-1)/2; i++){
        if (st[i]!=st[(length-1)-i]){
            kt = false;
        }
    }
    if (kt==true || kt==false && k==0 || k==0){
        return 1;
    }else {
        return 2;
    }
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
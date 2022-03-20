/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

int minimum;
string st;

void backtrack(int index, int scoret1, int scoret2, int round){
    if (index==10) minimum = min(minimum, 10);
    if (5 - round + scoret2 + 1< scoret1){
        minimum = min(minimum, round*2 + index%2 - 1);
        return;
    } else 
    if (5 - round + scoret1 + 1< scoret2){
        minimum = min(minimum, round*2 + index%2 - 1);
        return;
    }
    if (st[index]=='1'){
        if (index%2==0){
            backtrack(index+1, scoret1+1, scoret2, round + abs(index%2));
        } else {
            backtrack(index+1, scoret1, scoret2+1, round + abs(index%2));
        }
    } else 
    if (st[index]=='0'){
        backtrack(index+1, scoret1, scoret2, round + abs(index%2));
    }
    if (st[index]=='?'){
        for (char i = '0'; i<='1'; i++){
            if (i=='0') backtrack(index+1, scoret1, scoret2, round+abs(index%2));
            else 
            if (index%2==0){
                backtrack(index+1, scoret1, scoret2 + 1, round + abs(index%2));
            } else {
                backtrack(index+1, scoret1 + 1, scoret2, round + abs(index%2));
            }
        }
    }
}

void solve(){
    minimum = 11;
    backtrack(0,0,0,1);
    cout << minimum << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--){
        cin >> st;
        solve();
    }
}
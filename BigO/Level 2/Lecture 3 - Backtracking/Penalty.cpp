/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

string st;
int res;

bool check(int id, int pts1, int pts2, int round){
    if (id == 0){
        return((pts2 + 5 - round)<pts1);
    } else {
        return((pts1 + 5 - round)<pts2);
    }
}

void backtrack(int index, int pts1, int pts2, int round){
    if (index==10) return;
    if (st[index]=='1'){
        if (index%2==0){
            backtrack(index+1, pts1+1, pts2, round);
            if (check(0, pts1+1, pts2, round)){
                res = min(res, index+1);
            }
        } else {
            backtrack(index+1, pts1, pts2+1, round+1);
            if (check(1, pts1, pts2+1, round)){
                res = min(res, index+1);
            }
        }
    }
    if (st[index]=='0'){
        if (index%2==0){
            backtrack(index+1, pts1, pts2, round);
            if (check(0, pts1, pts2, round)){
                res = min(res, index+1);
            }
        } else {
            backtrack(index+1, pts1, pts2, round+1);
            if (check(1, pts1, pts2, round)){
                res = min(res, index+1);
            }
        }
    }
    if (st[index]=='?'){
        for (int i=0; i<=1; i++){
            if (index%2==0 && i == 0){
                backtrack(index+1, pts1, pts2, round);
                if (check(0, pts1, pts2, round)){
                    res = min(res, index+1);
                }
            } else
            if (index%2==1 && i == 0) {
                backtrack(index+1, pts1, pts2, round+1);
                if (check(1, pts1, pts2, round)){
                    res = min(res, index+1);
                }
            } else
            if (index%2==0 && i == 1){
                backtrack(index+1, pts1+1, pts2, round);
                if (check(0, pts1+1, pts2, round)){
                    res = min(res, index+1);
                }
            } else
            if (index%2==1 && i == 1) {
                backtrack(index+1, pts1, pts2+1, round+1);
                if (check(1, pts1, pts2+1, round)){
                    res = min(res, index+1);
                }
            }
        }
    }
}

void solve(){
    res = 11;
    backtrack(0, 0, 0, 1);
    cout << res << '\n';
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
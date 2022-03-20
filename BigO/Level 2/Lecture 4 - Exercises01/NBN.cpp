/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

bool done;
string st;
int k;
vector<bool> check;
vector<int> newstring;
int length;

void readData(){
    cin >> st >> k;
}

void backtrack(int index, int belowk, bool isTrue){
    if (index == length){
            done = true;
            return; 
    } 
    int x = st[index] - '0';
    if (isTrue) x = 0;
    for (int i=x; i<=9; i++){
        if (!check[i]){
            if (belowk < k){
                newstring.push_back(i);
                check[i] = true;
                backtrack(index+1, belowk + 1, isTrue | (i > x));
                if (done == true) return;
                newstring.pop_back();
                check[i] = false;
            }
        } else {
            newstring.push_back(i);
            backtrack(index+1, belowk, isTrue | (i > x));
            if (done==true) return;
            newstring.pop_back();
        }
    }
    return;
}

void solve(){
    backtrack(0, 0, false);
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
        done = false;
        readData();
        length = st.size();
        check.assign(10, false);
        newstring.clear();
        solve();
        for (int i=0; i<newstring.size(); i++){
            cout << newstring[i];
        }
        cout << '\n';
    }
}
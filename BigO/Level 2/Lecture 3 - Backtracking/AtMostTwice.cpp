/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

string st;
int cnt[19];
bool done;
vector<int> newstring;

void backtrack(int index, bool isTrue){
    int temp = st[index] - '0';
    if (index == st.size()){
        done = true;
        return;
    }
    if (isTrue){
        temp = 9;
    }
    for (int i = temp; i>=0; i--){
        if (cnt[i]<2){
            cnt[i]++;
            newstring.push_back(i);
            int temp1 = newstring[index];
            backtrack(index + 1, isTrue | i < (st[index] - '0'));
            if (done==true) break;
            cnt[i]--;
            newstring.pop_back();
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (cin >> st){
        done = false;
        newstring.clear();
        for (int i=0; i<=9; i++){
            cnt[i] = 0;
        }
        backtrack(0, false);
        for (int i=0; i<newstring.size(); i++){
            if (i==0 && newstring[i] != 0){
                cout << newstring[i];
            } else 
            if (i>0) cout << newstring[i];
        }
        cout << '\n';
    }
}
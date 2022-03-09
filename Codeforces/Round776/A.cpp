#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    string st;
    char x;
    cin >> T;
    for (int i=1; i<=T; i++){
        bool flag = false;
        cin >> st >> x;
        for (int i=0; i<st.size(); i++){
            if ((st[i] == x) && (i-0)%2==0 && (st.size()-1-i)%2==0){
                cout << "YES" << '\n';
                flag = true;
                break;
            }
        }
        if (flag==false) cout << "NO" << '\n';
    }
}
/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    string s1,s2;
    cin >> t;
    while (t--){
        cin >> s1 >> s2;
        for (int i=0; i<s1.size(); i++){
            if (s1[i]!=s2[i]){
                cout <<"B";
            } else{
                cout << "G";
            }
        }
        cout << '\n';
    }
}
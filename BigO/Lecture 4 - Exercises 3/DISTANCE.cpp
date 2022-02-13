#include <bits/stdc++.h>
using namespace std;
int dem1[1000],dem2[1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2;
    cin >> s1;
    cin >> s2;
    for (int i=0; i<s1.size(); i++){
        dem1[s1[i]]++;
    }
    for (int i=0; i<s2.size(); i++){
        dem2[s2[i]]++;
    }
    int res=0;
    for (char i='a'; i<='z'; i++){
        res += abs(dem1[i]-dem2[i]);
    }
    cout << res ;
}
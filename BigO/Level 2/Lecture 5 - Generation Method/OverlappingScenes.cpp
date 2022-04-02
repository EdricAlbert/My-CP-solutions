/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problems: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3401
**/

#include <bits/stdc++.h>

using namespace std;

int prefixSuffix(string a, string b){
    int res = -1;
    for (int i=0; i<a.size() && i<b.size(); i++){
        if (a.substr(a.size()-i-1) == b.substr(0,i+1)){
            res = max(res,i);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t, n, res, ID;
    cin >> t;
    ID = 0;
    while (t--){
        ID++;
        cin >> n;
        res = 100000;
        vector<string> words(n);
        for (string& x: words) cin >> x;
        sort(words.begin(), words.end());
        do{
            string cur = words[0];
            for (int i=1; i<n; i++){
                int len = prefixSuffix(cur, words[i]);
                cur+= words[i].substr(len+1);
            }
            int temp = cur.size();
            res = min(res, temp);
        } while(next_permutation(words.begin(),words.end()));
        cout << "Case " << ID << ": " << res << '\n';
    }
}
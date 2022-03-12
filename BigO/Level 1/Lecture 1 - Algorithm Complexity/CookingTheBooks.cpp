#include <bits/stdc++.h>

using namespace std;
string n;
int t,pos;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int tc=1; tc<=t; tc++){
        cin >> n;
        string st = n;
        for (int i=0; i<n.length(); i++){
            char maxx = n[i];
            for (int j=i+1; j<n.length(); j++){
                for (int j=i+1; j<n.length(); j++){
                    if (n[j]<=maxx && (n[j]!='0' || i!=0)){
                        maxx = n[j];
                        pos = j;
                    }
                }
            }
                if (maxx != n[i]){
                    char temp = st[i];
                    st[i] = st[pos];
                    st[pos] = temp;
                    break;
                }
        }
        cout << "Case #" << tc << ": " << st;
        st = n;
        for (int i=0; i<n.length(); i++){
            char maxx = n[i];
            for (int j=i+1; j<n.length(); j++){
                if (n[j]>=maxx && (n[j]!=0 || i!=0)){
                    maxx = n[j];
                    pos = j;
                }
            }
            if (maxx != n[i]){
                char temp = st[i];
                st[i] = st[pos];
                st[pos] = temp;
                break;
            }
        }
        cout << " " << st << '\n';
    }
}

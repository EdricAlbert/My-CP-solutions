#include <bits/stdc++.h>

using namespace std;

int x,y,c,n;
int f[401][401];    

void readData(){
    for (int i=0; i<=400; i++){
        fill(f[i],f[i]+401,-1);
    }
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> x >> y >> c;
        c--;
        f[x+200][y+200] = c;
    }
}

void solve(){
    int ans = 0;
    for (int u=0; u<=400; u++){
        for (int v=u+1; v<=400; v++){
            vector<int> s(1<<5);
            for (int col = 0; col<=400; col++){
                if (f[u][col]==-1 || f[v][col]==-1) continue;
                int record = (1<<f[u][col]) + (1<<f[v][col]);
                ans += s[(1<<4)-1-record];
                s[record]++;
            }
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    solve();
    return 0;
}
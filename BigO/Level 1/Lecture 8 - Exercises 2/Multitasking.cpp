#include <bits/stdc++.h>

using namespace std;

int n,m;
int startfrom, endat, intervals;
bool visited[1000001];


bool check(int start, int end){
    for (int i=start; i<end; i++){
        if (visited[i]) return false;
        visited[i] = true;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(;;){
        bool conflict = false;
        cin >> n >> m;
        memset(visited,false,sizeof(visited));
        if (n==0 & m==0) break;
        for (int i=1; i<=n; i++){
            cin >> startfrom >> endat;
            if (!conflict && !(check(startfrom,endat))){
                conflict = true;
            }
        }
        for (int i=1; i<=m; i++){
            cin >> startfrom >> endat >> intervals;
            while (startfrom<=1000000 && !conflict){
                if (!check(startfrom,endat)) conflict = true;
                startfrom = startfrom + intervals;
                endat = min(endat + intervals, 1000000);
            }
        }
        if (conflict) cout << "CONFLICT" << '\n';
            else cout << "NO CONFLICT" << '\n';
    }
}
#include <bits/stdc++.h>

struct info{
    int start;
    int end;
};

info line[100001];
int n,L,R;
using namespace std;

bool compare (const info& a, const info& b){
    if (a.start < b.start){
        return true;
    } else 
    if (a.start > b.start){
        return false;
    } else{
        return (a.end < b.end);
    }
}

void readData(){
    cin >> n >> L >> R;
    for (int i=1; i<=n; i++){
        cin >> line[i].start >> line[i].end;
    }
    sort(line+1,line+1+n,compare);   
}

void solve(){
    int res = 0;
    for (int i=2; i<=n; i++){
        if (line[i-1].end>=line[i+1].start){
            res = max((line[i].end)- (line[i].start),res);
        }
    }
    cout << res;
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
/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problems: https://www.spoj.com/PTIT/problems/BCTSP/
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 16;

int n;
int bestCost = 1e9;
int c[maxN][maxN];
vector<bool> visited;

void backtrack(int index, int sum, int citys){
    if (sum>=bestCost) return;
    if (citys==n){
        bestCost = min(bestCost, sum + c[index][1]);
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            visited[i] = true;
            backtrack(i, sum + c[index][i], citys+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    visited.assign(n+1, false);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> c[i][j];
        }
    }
    visited[1] = true;
    backtrack(1, 0, 1);
    cout << bestCost;
}
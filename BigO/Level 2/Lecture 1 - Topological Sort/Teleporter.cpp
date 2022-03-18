/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5+1;
int n, k;
vector<int> graph[maxN];
long long result = 0;

void readData(){
    cin >> n >> k;
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        if (i==1){
            if (x!=1) result += 1;
        } else {
            graph[x].push_back(i);
        }
    }
}


void bfs(){
    queue<int> q;
    q.push(1);
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: graph[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1 ;
                int temp1 = dist[v];
                int temp2 = dist[u];
                if (dist[v] > k){
                    dist[v] = 1;
                    result+=1;
                }
                q.push(v);
            }
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    bfs();
}
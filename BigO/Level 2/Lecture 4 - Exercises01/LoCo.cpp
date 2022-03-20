/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4+1;

long long f[maxN];
int n;
vector<long long> graph[maxN];
long long a[maxN];
long long maxx;
vector<bool> visited;
int result;
int indegree[maxN];

bool check(long long need){
    int left = 1;
    int right = n;
    while (right>=left){
        int mid = (left+right)/2;
        if (a[mid]==need){
            result = mid;
            return true;
        }
        if (a[mid]>need) right = mid - 1;
            else left = mid + 1;
    }
    return false;
}

void readData(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n); //(N log N)
    for (int i=1; i<=n; i++){ // O(n^2 * log(n))
        for (int j = i+1; j<=n; j++){
            if (check(a[i]+a[j])){
                graph[i].push_back(result);
                graph[j].push_back(result);
                indegree[result]+=2;
            }
        }
    }
}

void kahn(){
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (indegree[i]==0) q.push(i);
        f[i] = 1;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: graph[u]){
            f[v] = max(f[v], f[u]+1);
            maxx = max(maxx, f[v]);
            indegree[v]--;
            if (indegree[v]==0) q.push(v);
        }
    }
}

void solve(){
    maxx = 1;
    kahn();
    cout << maxx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    readData();
    solve();
}
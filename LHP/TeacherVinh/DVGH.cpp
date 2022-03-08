#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

typedef pair<int, int> pii;
int dist[1001];
vector<vector<pii>> adj(1001);
int pi[1001], qi[1001], ki[1001];
int n, m, y, p, q, k, t, a, b;

void readData(){
    cin >> n >> m >> y >> p >> q >> k;
    for (int i=1; i<=m; i++){
        cin >> a >> b >> t;
        adj[a].push_back({ b, t });
        adj[b].push_back({ a, t });
    }
    int r;
    int temp;
    for (int i=1; i<=p; i++){
        cin >> temp >> r;
        pi[temp] = r;
    }
    for (int i=1; i<=q; i++){
        cin >> temp >> r;
        qi[temp] = r;
    }
    for (int i=1; i<=k; i++){
        cin >> temp >> r;
        ki[temp] = r;
    }
}

void dijkstra(int s){
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, s });
    dist[s] = 0;
    while (!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        int temp = dist[u];
        if (tmp.first != dist[u]) continue;
        for (int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            int temp1 = dist[v];
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

void solve(){
    dijkstra(y);
    int minA = INF;
    int minB = INF;
    int minC = INF;
    int minABC = INF;
    for (int i = 1; i<=n; i++){
        int temp = dist[i];
        minA = min(pi[i]+dist[i],minA);
        minB = min(qi[i]+dist[i],minB);
        minC = min(ki[i]+dist[i],minC);
    }
    int minAC = minA + minC;
    int minAB = minA + minB;
    int minBC = minB + minC;
    for (int i=1; i<=n; i++){
        minAC = min(minAC, pi[i]+ki[i]+dist[i]);
        minAB = min(minAB, pi[i]+qi[i]+dist[i]);
        minBC = min(minBC, qi[i]+ki[i]+dist[i]);
    }
    for (int i=1; i<=n; i++){
        minABC = min(minABC, pi[i]+qi[i]+ki[i]+dist[i]);
    }
    int result = INF;
    result = min(result, minABC);
    result = min(result, minAB + minC);
    result = min(result, minAC + minB);
    result = min(result, minBC + minA);
    result = min(result, minA + minB + minC);
    cout << minA << '\n';
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("DVGH.inp","r",stdin);
    freopen("DVGH.out","w",stdout);
    fill(pi,pi+1001,INF);
    fill(qi,qi+1001,INF);
    fill(ki,ki+1001,INF);
    readData();
    solve();
    return 0;
}
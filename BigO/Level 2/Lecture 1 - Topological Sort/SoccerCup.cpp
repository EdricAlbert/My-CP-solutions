/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4+1;

int n, m;
int indegree[maxN];
int outdegree[maxN];
bool check;

bool kahn(vector<int> graph[maxN]){
    queue<int> q;
    bool checkin = true;
    vector<int> result;
    for (int i=1; i<=n; i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int count = 0;
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v: graph[u]){
            count++;
            indegree[v]--;
            if (indegree<0){
                check = false;
                return false;
            }
            if (indegree[v] == 0){
                q.push(v);
            }
        }

        if  (count==0 && outdegree[u]==0) checkin = false;
    }
    if (result.size()!=n){
        check = true;
        return false;
    }
    else if(checkin == false) {
        check = false;
        return false;
    }
    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << '\n';
    return true;
}

void solve(){
    check = true;
    vector<int> graph[maxN];
    memset(indegree,0,sizeof(indegree));
    memset(outdegree,0,sizeof(outdegree));
    cin >> n >> m;
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
        outdegree[v]++;
    }
    bool kt = kahn(graph);
    if (kt==false){
        if (check==false){
            cout << "missing hints" << '\n';
        } else {
            cout << "recheck hints" << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
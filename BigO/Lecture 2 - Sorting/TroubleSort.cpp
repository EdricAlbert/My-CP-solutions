#include <bits/stdc++.h>

using namespace std;

vector<int> a,b;
int n;

void readData(){
    cin >> n;
    int x;
    a.clear();
    b.clear();
    for (int i=0; i<n; i++){
        cin >> x;
        if (i%2==0) 
            a.push_back(x);
        else
            b.push_back(x);
    }
}

bool comp (int a, int b){
    return a>b;
}

void solve(int t){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(), comp);
    vector<int> merge;
    for (int x: a){
        merge.push_back(x);
        if (!b.empty()){
            merge.push_back(b.back());
            b.pop_back();
        }
    }
    bool flag = false;
    for (int i=0; i<merge.size()-1; i++){
        if (merge[i]>merge[i+1]){
            cout << "Case #" << t << ": " << i << '\n';
            flag = true;
            break;
        }
    }
    if (flag==false){
        cout << "Case #" << t << ": " << "OK" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        readData();
        solve(t);
    }    
    return 0;
}
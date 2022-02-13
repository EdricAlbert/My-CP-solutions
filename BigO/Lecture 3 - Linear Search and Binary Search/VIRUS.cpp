#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    for(int i = 0; i < a.size(); i++){
        if(b[i] == '*')
            continue;
        if(a[i] != b[i])
            return false;
    }
    return true;
}

bool search(string a, string b){
    if(a.size() < b.size())
        return false;
    
    int na = a.size(), nb = b.size();

    for(int i = 0; i < na - nb + 1; i++){
        string s = a.substr(i, nb);
        if(compare(s, b))
            return true;
    }
    return false;
}

void solve(int iTest){
    cout << "Data set #" << iTest << ":\n";
    int n; cin >> n;
    vector <string> badVirus(n);
    for(auto &x: badVirus)
        cin >> x;
    
    int m; cin >> m;
    vector <string> virus(m);
    for(auto &x: virus)
        cin >> x;

    for(int i = 0; i < m; i++){
        cout << "Virus #" << i+1 << ": ";
        bool isInvalid = false;
        for(int j = 0; j < n; j++)
            if(search(virus[i], badVirus[j])){
                isInvalid = true;
                break;
            }
        if(!isInvalid)
            cout << "Cool! Victor can take it with him!" << '\n';
        else
            cout << "Nuts. This virus is illegal in Hawaii!" << '\n';
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}
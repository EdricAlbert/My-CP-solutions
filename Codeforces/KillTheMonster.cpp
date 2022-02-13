#include <bits/stdc++.h>

using namespace std;

int k, w, dC, dM;
long long a, newdC, newhC, hC, hM;

void readData(){
    cin >> hC >> dC;
    cin >> hM >> dM;
    cin >> k >> w >> a;
}

string solve(){
    for (int i=0; i<=k; i++){
        newhC = hC + i*a;
        newdC = dC + (k-i)*w;
        long long atemptM, atemptC;
        if (newhC%dM>0) atemptM = newhC/dM + 1;
            else 
        atemptM = newhC/dM;
        if (hM%newdC>0) atemptC = hM/newdC + 1;
            else
        atemptC = hM/newdC;
        if ((atemptM)>=(atemptC)){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while (T--){
        readData();
        cout << solve() << '\n';
    }
    return 0;
}
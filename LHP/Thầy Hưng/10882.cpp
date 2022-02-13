#include <bits/stdc++.h>

using namespace std;
int X,Y,Z;
void readData(){
    cin >> X >> Y >> Z;
}

void solve(){
    int check = max(X,max(Y,Z));
    if (check>100) cout << "The records are faulty.";
        else {
            int low = (X+Y+Z-100)/2;
            if ((X+Y+Z-100)%2==1) low++;
            if (low<=0) low = 1;
            int high = min(X,min(Y,Z));
            if (low>high) cout << "The records are faulty";
                else {
                    cout << "Between " << low << " and " << high << " times.";
                }
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int testcases;
    cin >> testcases;
    for (int i=1; i<=testcases; i++){
        cout << "Case #" << i  << ": ";
        readData();
        solve();
        cout << '\n';
    }
}
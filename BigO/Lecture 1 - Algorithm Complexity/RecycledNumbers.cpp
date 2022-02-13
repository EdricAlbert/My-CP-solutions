#include <bits/stdc++.h>

using namespace std;
int t,x,y,a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> a >> b;
        x = 1;
        y = a;
        while (y>=10){
            x = x * 10;
            y = y / 10;
        }
        int res = 0;
        for (int i=a; i<=b; i++){
            y = i;
            bool kt=true;
            while (kt==true){
                y = (y/10) + ((y%10)*x);
                if (y==i){
                    break;
                }
                if (y>i && y<=b){
                    res = res + 1;
                }
            }
        }
        cout << "Case #" << i << ": " << res << '\n';
    }
}
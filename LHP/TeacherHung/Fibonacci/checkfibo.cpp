#include <bits/stdc++.h>

using namespace std;

long long f[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long i = 3;
    f[1] = 1;
    f[2] = 1;
    double side1 = (1+sqrt(5))/2 * (1+sqrt(5))/2;
    double side2 = (1-sqrt(5))/2 * (1-sqrt(5))/2;
    while (true){
        f[i] = f[i-1] + f[i-2];
        double temp = 1/(sqrt(5));
        side1 = (1 + sqrt(5))/2 * side1;
        side2 = (1 - sqrt(5))/2 * side2;
        temp = temp*(side1-side2);
        long long result  = (long long)temp;
        if (result!=f[i]){
            cout << i;
            break;
        }
        i = i + 1;
    }
}
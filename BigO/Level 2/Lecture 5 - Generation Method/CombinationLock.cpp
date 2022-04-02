/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problems: https://codeforces.com/problemset/problem/1097/B
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 16;

int n;
bool kt = false;
int bin[maxN];
int a[maxN];

void genRotate(int index){
    if (kt==true) return;
    if (index==n+1){
        int base = 0;
        for (int i=1; i<=n; i++){
            if (bin[i]==0){
                base-=a[i];
            } else {
                base+=a[i];
            }
        }
        if (base%360==0){
            kt = true;
        }
    } else {
        for (int i=0; i<=1; i++){
            bin[index] = i;
            genRotate(index+1);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    genRotate(1);
    if (kt==false){
        cout << "NO";
    } else cout << "YES";
}
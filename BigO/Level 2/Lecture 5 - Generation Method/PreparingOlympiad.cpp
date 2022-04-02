/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problems: https://codeforces.com/problemset/problem/550/B
**/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 16;

int n;
int bin[maxN];
int a[maxN];
int r, l, k;
int res = 0;

void generationBin(int index){
    if (index == n){
        long long sum = 0;
        int problems = 0;
        int minScore = 10000000;
        int maxScore = 0;
        for (int i=0; i<n; i++){
            if (bin[i]==1){
                sum+= a[i];
                problems++;
                maxScore = max(maxScore, a[i]);
                minScore = min(minScore, a[i]);
            }
        }
        if (problems>=2 && l <= sum && sum <= r && maxScore - minScore >= k){
                res++;
        }
    } else 
    for (int i=0; i<=1; i++){
        bin[index] = i;
        generationBin(index+1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> l >> r >> k;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    generationBin(0);
    cout << res;
}
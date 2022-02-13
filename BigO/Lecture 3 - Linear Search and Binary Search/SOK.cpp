#include <bits/stdc++.h>

using namespace std;

long long k;

void readData(){
    int ID;
    cin >> ID >> k;
}

long long findquantity(long long x){
    long long res = (x/3) + (x/5) + (x/7);
    res -= x/15 + x/35 + x/21;
    res += x/105;
    return res;
}

long long solve(long long k){
    long long left = 3;
    long long right = 1e18;
    while (left<=right){
        long long mid = left + (right-left)/2;
        long long index = findquantity(mid);
        if (index==k && ((mid%3==0) || (mid%5==0) || (mid%7==0))){
            return mid;
        }
        if (index<k) left = mid+1;
            else
        right = mid - 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.inp","r",stdin);
    readData();
    cout << solve(k);
    return 0;
}
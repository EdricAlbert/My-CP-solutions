/**
 * author: edricalbert
 * created: 27.2.141.46  
 * Problems: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3650
**/

#include <bits/stdc++.h>

using namespace std;

int present;
string st;
int behind, front, pos;
string backst, frontst;
string res;
int maxDist = 0;

void swap(int i, int j, string& sts){
    char o = sts[i];
    sts[i] = sts[j];
    sts[j] = o;
}

void backPermutation(){
    int i = backst.size() - 2;
    while (i>=0 && backst[i] <= backst[i+1]) i--;
    if (i<0) return;
    int k = backst.size() - 1;
    while (backst[k] >= backst[i]) k--;
    swap(i, k, backst);
    i++;
    k = backst.size() - 1;
    while (i<k){
        swap(i, k, backst);
        i++;
        k--;
    }
    int minDist = 100000;
    for (int i=0; i<backst.size()-1; i++){
        minDist = min(minDist, abs(backst[i] - backst[i+1]));
    }   
    if (minDist >= maxDist) {
        maxDist = minDist;
        res = backst;
        pos = behind+1;
    }
}

void frontPermutation(){
    int i = frontst.size() - 2;
    while (i>=0 && frontst[i] >= frontst[i+1]) i--;
    if (i<0) return;
    int k = frontst.size() - 1;
    while (frontst[k] <= frontst[i]) k--;
    swap(i, k, frontst);
    i++;
    k = frontst.size() - 1;
    while (i<k){
        swap(i, k, frontst);
        i++;
        k--;
    }
    int minDist = 100000;
    for (int i=0; i<frontst.size()-1; i++){
        minDist = min(abs(frontst[i] - frontst[i+1]),minDist);
    }   
    if (minDist > maxDist) {
        maxDist = minDist;
        res = frontst;
        pos = present;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (cin >> st){
        backst = st;
        frontst = st;
        maxDist = 0;
        behind = 10;
        front = 10;
        pos = 0 ;
        present =11;
        while (behind--){
            backPermutation();
        }
        while (front--){
            present++;
            frontPermutation();
        }
        int minDist = 10000;
        for (int i=0; i<st.size()-1; i++){
            minDist = min(minDist, abs(st[i]-st[i+1]));
        }
        if (minDist >= maxDist && pos > 11){
            maxDist = minDist;
            res = st;
        }
        cout << res << maxDist << '\n';
    }
}
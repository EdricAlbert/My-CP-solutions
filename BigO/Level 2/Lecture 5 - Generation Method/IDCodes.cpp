/**
 * author: edricalbert
 * created: 27.2.141.46
 * Problems: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=82  
**/

#include <bits/stdc++.h>

using namespace std;

string st;
bool kt;

void swap(int i, int j){
    char o = st[i];
    st[i] = st[j];
    st[j] = o;
}

bool nextPermutation(){
    int i = st.size() - 2;
    while (i>=0 && st[i]>=st[i+1]) i--;
    if (i<0) return false;
    int k = st.size() - 1;
    while (st[k] <= st[i]) k--;
    swap(i,k);
    i++;
    k = st.size() - 1;
    while (i<k){
        swap(i,k);
        i++;
        k--;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (cin >> st){
        if (st=="#"){
            break;
        }
        kt = nextPermutation();
        if (kt==true) cout << st << '\n';
            else 
        cout << "No Successor" << '\n';
    }
}
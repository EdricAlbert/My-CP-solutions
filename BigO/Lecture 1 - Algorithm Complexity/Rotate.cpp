#include <bits/stdc++.h>

using namespace std;

int n,k;
char a[51][51];

void readData(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}

bool limit(int u, int p){
    return(u>=1 && p<=n && p>=1 && u<=n);
}

bool check(int x, int y){
    if (a[x][y]=='.') return false;
    int cheophai = 0;
    int cheotrai = 0;
    int ngang = 0;
    int doc = 0;
    for (int i=0; i<k; i++){
        if (limit(x+i,y+i) && a[x+i][y+i]==a[x][y]) cheophai++;
        if (limit(x+i,y-i) && a[x+i][y-i]==a[x][y]) cheotrai++;
        if (limit(x,y+i) && a[x][y+i]==a[x][y]) ngang++;
        if (limit(x+i,y) && a[x+i][y]==a[x][y]) doc++;
    }
    return (cheophai == k || cheotrai == k || ngang == k || doc == k);
}

int solve(){
    int R=0;
    int B=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (check(i,j)){
                if (a[i][j]=='R') R=1;
                if (a[i][j]=='B') B=1;
                if (R+B==2) return 3;
            }
        }
    }
    if (R==1) return 0;
    if (B==1) return 1;
    return 2;
}

void dorotate(){
    int mark;
    for (int i=1; i<=n; i++){
        mark = n;
        for (int j=n; j>=1; j--){
            if (a[i][j]!='.'){
                a[i][mark] = a[i][j];
                mark--;
            }
        }
        while (mark>=1){
            a[i][mark] = '.';
            mark--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases;
    string res[4] = {"Red","Blue","Neither","Both"};
    cin >>  testcases;
    for (int test=1; test<=testcases; test++){
        cout << "Case #" << test <<": ";
        readData();
        dorotate();
        cout << res[solve()] << '\n';
    }
    return 0;
}
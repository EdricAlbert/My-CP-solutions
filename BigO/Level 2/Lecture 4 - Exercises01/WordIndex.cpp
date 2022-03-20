/**
 * author: edricalbert
 * created: 27.2.141.46  
**/

#include <bits/stdc++.h>

using namespace std;

map <string,int> encode;
string s;
void Need(){
    int pos = 1;
    string st;
    for (char i = 'a'; i<='z'; i++){
        st = i;
        encode[st] = pos++;
    }
    for (char i = 'a'; i<='z'-1; i++){
        for (char j = i+1; j<='z'; j++){
            st = i + j;
            encode[st] = pos++;
        }
    }
    for (char i = 'a'; i<='z'-2; i++){
        for (char j = i+1; j<='z'-1; j++){
            for (char z = j + 1; z<='z'; z++){
                st = i + j + z;
                encode[st] = pos++;
            }
        }
    }
    for (char i = 'a'; i<='z'-3; i++){
        for (char j = i+1; j<='z'-2; j++){
            for (char k = j + 1; k<='z'-1; k++){
                for (char s = k + 1; s<='z'; s++){
                    st = i + j + k + s;
                    encode[st] = pos++;
                }
            }
        }
    }
    for (char i = 'a'; i<='z'-4; i++){
        for (char j = i+1; j<='z'-3; j++){
            for (char k = j + 1; k<='z'-2; k++){
                for (char s = k + 1; s<='z'-1; s++){
                    for (char r = s + 1; r<='z'; r++){
                        st = i + j + k + s + r;
                        encode[st] = pos++;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Need();
    while (cin >> s){
        bool kt = true;
        for (int i = 0; i<s.size()-1; i++){
            if (s[i]>s[i+1]){
                cout << 0 << '\n';
                kt = false;
            }
        }
        if (kt){
            int temp = encode[s];
            cout << temp << '\n';
        }
    }
}
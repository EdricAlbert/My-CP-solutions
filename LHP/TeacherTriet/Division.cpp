#include <bits/stdc++.h>

using namespace std;
string s1, s2;
void readData(){
    cin >> s1 >> s2;
}

bool compare(string a, string b){
    for (int i=0; i<a.size(); i++){
        if (a[i]<b[i]) return false;
        if (a[i]>b[i]) return true;
    }
    return true;
}

string subtraction(string a, string b){
    vector<int> remember;
    string ans = "";
    remember.assign(remember.size(),0);
    for (int i=b.size(); i<a.size(); i++){
        b = '0' + b;
    }
    remember.push_back(0);
    for (int i=a.size()-1; i>=0; i--){
        int x = atoi(a[i]);
        int y = atoi(b[i]);
        if (x<y){
           x = 10 + x - remember[a.size() - i - 1];
           string temp = to_string(x-y);
           ans = temp + ans;
           remember.push_back(1); 
        }
    }
    return ans;
}

string multiplication(string a, string b){
    int cnt[10000];
    int prison[100000];
    memset(prison,0,sizeof(prison));
    memset(cnt,0,sizeof(cnt));
    for (int i = b.length()-1; i>=0; i--){
        for (int j = a.length()-1; j>=0; j--){
            prison[a.size()-1-b.size()-1-j+1] += (a[j]-'0')*(b[i]-'0');
        }
    }
    string kq = "";
    char kt[20];
    for (int i=1; i<=(a.length()+b.length()); i++){
        if (prison[i] == 0 && i>=(a.length()+b.length()-1)) break;
        prison[i] = prison[i]+cnt[i-1];
        cnt[i] = prison[i]/10;
        int temp = prison[i]%10;
        kq = (temp+'0') + kq;
    }
    return kq;
}

string operation(string a, string b){
    string temp;
    string ready;
    for (int i=0; i<=9; i++){
        temp = multiplication(b,i);
        if (compare(a,temp)){
            ready = temp;
        } else {
            break;
        }
    }
    return subtraction(a,temp);
}

void solve(){
    int pos = 0;
    string temp;
    while (pos!=s1.size()){
        temp = s1.substr(pos,s2.length());
        pos = pos + s2.length();
        if(!compare(temp,s2)){
            temp = temp + s1.substr(pos+s2.length(),1);
            pos++;
        }
        temp = operation(temp,s2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    readData();
    solve();
    return 0;
}
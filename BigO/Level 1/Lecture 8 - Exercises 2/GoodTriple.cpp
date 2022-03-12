#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout.tie(0);
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  string s;
  cin >> s;
  int n = (int) s.size();
  ll ans = 0;
  ll cnt = n;
  for (int x = n - 1; x >= 0; x--) {
    for (int k = 1; x + 2 * k < cnt; k++) {
      if (s[x] == s[x + k] && s[x + k] == s[x + 2 * k]) {
        cnt = x + 2 * k;
        break;
      }
    }
    ans += n - cnt;
  }
  cout << ans << endl;
}

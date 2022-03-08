#include <bits/stdc++.h>

using namespace std;
const int N = 100007;

int a[N], b[N];
int n, m, y00, y11;

int main() {
	cin >> n >> m >> y00 >> y11;
	assert(1 <= n && n <= 1e5);
	assert(0 <= m && m <= 1e5);
	//assert(0 <= y0 && y0 <= 1e7);
	//assert(0 <= y1 && y1 <= 1e7 && y0 != y1);
	for (int i = 0; i < n; ++i){
        cin >> a[i];
        assert(-1e7 <= a[i] && a[i] <= 1e7);
	}
	for (int i = 0; i < m; ++i){
        cin >> b[i];
        assert(-1e7 <= b[i] && b[i] <= 1e7);
	}
	int k = 0, j = 0, last = -1;
	for (int i = 0; i < n; ++i) {
		while (j < m && abs(a[i] - b[j+1]) < abs(a[i] - b[j]))
            ++j;
		if (last < j || (i > 0 && abs(a[i-1] - b[j]) == abs(a[i] - b[j]))) {
            ++k;
            last = j;
        }
        else if (j < m && abs(a[i] - b[j+1]) == abs(a[i] - b[j])) {
            ++k;
            last = ++j;
        }
        else
            last = j;
	}
	cout << n - k;
}

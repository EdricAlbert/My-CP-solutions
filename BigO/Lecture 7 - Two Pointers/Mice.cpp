    #include <bits/stdc++.h>

    using namespace std;

    int n, m, x, y, a[100001], b    [100001];

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        cin >> n >> m >> x >> y;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        for (int i=1; i<=m; i++){
            cin >> b[i];
        }
        int start = 0;
        int wellfed = 0;
        int j = 1;
        for (int i=1; i<=n; i++){
            while (j<m && abs(a[i]-b[j])>abs(a[i]-b[j+1])){
                j++;
            }
            if (start<j || (i > 0 && abs(a[i]-b[j]) == abs(a[i-1]-b[j]))){
                wellfed++;
                start = j;
            }   else 
            if (j < m && abs(a[i] - b[j]) == abs(a[i] - b[j+1])){
                wellfed++;
                start = j+1;
            }   else {
                start = j;
            }
        }
        cout << n - wellfed;
    }
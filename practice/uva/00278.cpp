#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) cout << #a << ": "; \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;

void solve() {
    char c;
    int n,m;
    cin >> c >> n >> m;
    if (n>m) swap(n,m);

    switch (c) {
        case 'r':
            cout << min(m,n) << "\n";
            break;
        case 'k': {
            int rowA = m/2;
            int rowA_cnt = n/2 + (n%2);
            cout << rowA*rowA_cnt + (m-rowA)*(n-rowA_cnt) << "\n";
            break;
        }
        case 'Q':
            cout << min(m,n) << "\n";
            break;
        case 'K': {
            int rowA = m/2;
            int rowA_cnt = n/2 + (n%2);
            cout << rowA*rowA_cnt << "\n";
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

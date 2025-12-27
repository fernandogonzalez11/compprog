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
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;

    int ops = 0;
    while (n < m) {
        a += a;
        n += n;
        ops++;
    }

    int idx = a.find(b);
    
    if (idx!=-1) {
        cout << ops << "\n";
        return;
    }

    a += a;
    n += n;

    idx = a.find(b);

    if (idx!=-1) {
        cout << ops+1 << "\n";
        return;
    } else cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

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
    int a,b;
    cin >> a >> b;

    if (a==0 && b==0) exit(0);

    set<int> x,y;
    int u;
    loop(i,0,a) {
        cin >> u;
        x.insert(u);
    }
    loop(i,0,b) {
        cin >> u;
        y.insert(u);
    }

    int canX = x.size(), canY = y.size();
    for (auto l : x)
        if (y.count(l)) canX--;

    for (auto l : y)
        if (x.count(l)) canY--;

    cout << min(canX,canY) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (true) solve();
    
    return 0;
}

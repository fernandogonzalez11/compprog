#include <algorithm>
#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
    int n;
	cin>>n;

    vec<vec<pair<int,bool>>> g(n);

    loop(i,0,n-1) {
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        u--, v--;
        // x > y -> pu > pv
        bool val = x > y;
        g[u].push_back({v,val});
        g[v].push_back({u,!val});
    }

    vec<int> res(n,INF);
    vec<bool> vis(n,false);
    queue<pair<int,bool>> q;

    res[0] = 0;
    vis[0] = true;
    for (auto p : g[0]) {
        q.push(p);
        vis[p.F] = true;
    }

    int lo = -1, hi = 1;
    while (!q.empty()) {
        int v;
        bool val;
        tie(v,val) = q.front();
        q.pop();

        // cout << "visiting:" << v<< "\n";

        // past > v -> v < past -> choose lower
        res[v] = val ? lo-- : hi++;

        for (auto p : g[v])
            if (!vis[p.F]) {
                vis[p.F] = true;
                q.push(p);
            }
    }

    // printarr(res);

    int dif = 1 - *min_element(all(res));
    loop(i,0,n) cout << res[i]+dif << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
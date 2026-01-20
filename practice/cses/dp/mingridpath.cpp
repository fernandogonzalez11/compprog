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

    vec<string> grid(n);
    loop(i,0,n) cin>>grid[i];

    vec<vec<bool>> vis(n,vec<bool>(n, false));
    deque<pii> q;
    q.push_back({0,0});
    vis[0][0] = true;

    string final = "";
    final += grid[0][0];

    while (!q.empty()) {
        char minc = 127;

        // cout << "in queue:\n";
        for (auto &p : q) {
            // cout << p.F << " " << p.S << "\n";

            if (p.F < n-1) minc = min(minc, grid[p.F+1][p.S]);
            if (p.S < n-1) minc = min(minc, grid[p.F][p.S+1]);
        }

        final += minc;

        int sz = q.size();
        loop(_,0,sz) {
            auto p = q.front();
            q.pop_front();

            if (p.F < n-1 && grid[p.F+1][p.S] == minc && !vis[p.F+1][p.S]) {
                vis[p.F+1][p.S] = true;
                q.push_back({p.F+1, p.S});
            }

            if (p.S < n-1 && grid[p.F][p.S+1] == minc &&  !vis[p.F][p.S+1]) {
                vis[p.F][p.S+1] = true;
                q.push_back({p.F, p.S+1});
            }
        }
    }

    final.resize(final.size()-1);
    cout << final << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
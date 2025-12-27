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

using pii = pair<int,int>;
void solve() {
    int n;
    cin >> n;

    vec<vec<pii>> g(n, vec<pii>());
    // vec<pii> e(n-1);
    // vec<int> firstappearance(n, INF);
    loop(i,0,n-1) {
        int x,y;
        cin >> x >> y;
        x--, y--;

        // e[i] = {x,y};
        g[x].push_back({y,i});
        g[y].push_back({x,i});
        // firstappearance[x] = min(firstappearance[x],i);
        // firstappearance[y] = min(firstappearance[y],i);
    }

    {
        // dfs

        int m = 0;
        stack<tuple<int,int,int>> s;
        vec<bool> vis(n,false);

        // node, readings, min first appearance
        vis[0]=true;
        for (auto ngb : g[0]) {
            vis[ngb.F] = true;
            s.push({ngb.F,1,ngb.S});
        }

        while (!s.empty()) {
            int node,readings,f;
            tie(node,readings,f) = s.top();
            s.pop();

            m = max(m,readings);

            for (auto ngb : g[node]) {
                if (vis[ngb.F]) continue;

                // cout << "vis:" << node << " " << ngb << " " << readings << "\n";

                if (ngb.S<f)
                    s.push({ngb.F, readings+1, ngb.S});
                else
                    s.push({ngb.F, readings, ngb.S});

                vis[ngb.F] = true;
            }
        }

        cout << m << "\n";
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

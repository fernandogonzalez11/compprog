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

pii mexf(vec<int> &v) {
    int n = v.size();
    int mex = 0, mexpos = -1;

    if (v[0] == 0) {
        loop(i,1,n) {
            if (v[i]-v[i-1] > 1) {
                mex = v[i-1]+1;
                mexpos = i-1;
                break;
            }
        }
    }

    return {mex,mexpos};
}

/*
void solve() {
    int n,x;
    cin>>n>>x;
    vec<int> v(n);
    loop(i,0,n) cin >> v[i];
    sort(all(v));

    v.push_back(INF);

    int mex, mexpos;

    set<int> s;
    loop(i,0,n) {
        // 0 1 1 2 3 4 (+2) -> 0 1 3 2 5 4
        if (s.count(v[i])) v[i] += x;
        s.insert(v[i]);
    }
    sort(all(v));

    // printarr(v);

    tie(mex, mexpos) = mexf(v);
    cout << mex << "\n";
}
*/

void solve() {
    int n,x;
    cin>>n>>x;
    vec<int> v(n), freq(n+2,0);
    loop(i,0,n) {
        int x;
        cin>>x;
        if (x >= n) continue;
        freq[x]++;
    }

    for (int i = 0; i < freq.size(); i++) {
        if (!freq[i]) {
            cout << i << "\n";
            return;
        }

        // for (int j = 1; j <= freq[i]-1; j++) {
        //     if (i + x*j >= n) break;
        //     freq[i+x*j]++;
        // }

        // more efficient and will propagate similarly
        if (i+x <= n) freq[i+x] += freq[i]-1;
        // freq[i] = 1 // optional
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
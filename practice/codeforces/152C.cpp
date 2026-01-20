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
    int n,m;
    cin>>n>>m;

    vec<string> v(n);
    loop(i,0,n) cin >> v[i];

    int amt = 1;
    loop(i,0,m) {
        set<char> s;
        loop(j,0,n) s.insert(v[j][i]);
        amt *= s.size();
        amt %= MOD;
    }

    cout << amt << "\n";
}

/*
why it worked:
In this task, it was necessary to understand that in position 1
Vasya can get any name of a special form. More exactly, it's the
name of form s = s1 s2 s3 s4 ... sm, where s1 — the first letter
of any of the names, s2 — the second letter of any of the names,
... sm — m-th letter of any of the names. Then the answer to the
problem is the product of cnti (1 ≤ i ≤ m), where cnti is a number
of different letters in the names placed in position i.
*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
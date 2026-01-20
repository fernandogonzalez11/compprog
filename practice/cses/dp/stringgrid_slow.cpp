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

string getstr(vec<string> &v, vec<vec<bool>> &dp, int i, int j) {
    string s;
    while (i || j) {
        s += v[i][j];
        dp[i][j] ? i-- : j--;
    }

    reverse(all(s));
    return s;
}

void solve() {
    int n;
    cin>>n;
    vec<string> v(n);
    loop(i,0,n) cin>>v[i];

    // best path parent
    // 0 -> left, 1 -> up
    vec<vec<bool>> dp(n, vec<bool>(n));
    loop(i,0,n) {
        dp[0][i] = 0;
        dp[i][0] = 1;
    }

    string sl, su;

    loop(i,1,n) {
        loop(j,1,n) {
            // make the 2 compare strings
            sl = getstr(v, dp, i, j-1), su = getstr(v, dp, i-1, j);
            dp[i][j] = su < sl;
        }
    }

    cout << v[0][0] << (dp[n-1][n-1] ? su : sl) << v[n-1][n-1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
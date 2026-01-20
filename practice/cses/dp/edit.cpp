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
    string s1, s2;
    cin>>s1>>s2;

    int w1 = s1.size(), w2 = s2.size();
    // pref excl 1, pref excl 2
    int dp[w1+1][w2+1];
    
    loop(i,0,w2+1) dp[0][i] = i;
    loop(i,0,w1+1) dp[i][0] = i;

    loop(i,1,w1+1) {
        loop(j,1,w2+1) {
            dp[i][j] = min({
                // match when equal, modify when different
                (s1[i-1]==s2[j-1]) ? dp[i-1][j-1] : 1  + dp[i-1][j-1],
                // remove the last char from s1
                // analogue: adding a matching char to the end of s2, then immediately match it
                // WARM  -> WAR|M -> WAR
                // FAR   -> FAR|M -> FAR
                1 + dp[i][j-1],
                // add a matching char to the end of s1, then immediately match it
                // TOW   -> TOW|N -> TOW
                // TOWN  -> TOW|N -> TOW
                1 + dp[i-1][j]
            });
        }
    }

    // loop(i,0,w1+1) {loop(j,0,w2+1) cout << dp[i][j] << " "; cout << "\n"; }

    cout << dp[w1][w2] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
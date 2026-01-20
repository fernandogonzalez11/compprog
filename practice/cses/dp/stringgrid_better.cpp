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

    vec<string> last;
    {
        string s;
        loop(i,0,n) {
            s += v[0][i];
            last.push_back(s);
        }
    }

    // printarr(last);

    // O(n^3)
    loop(i,1,n) {
        // O(~1)
        last[0] += v[i][0];

        // O(n^2)
        loop(j,1,n) {
            // O(~1)
            if (last[j] < last[j-1]) {
                last[j] += v[i][j];
            // O(n)
            } else {
                last[j] = last[j-1];
                last[j] += v[i][j];
            }
        }
    }

    cout << last[n-1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
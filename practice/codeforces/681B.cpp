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

bool solve() {
    int n;
    cin >> n;

    array<int, 3> coins = { 1234567, 123456, 1234 };

    int maxA = n / coins[0];
    int maxB = n / coins[1];

    loop(a,0,maxA+1) {
        loop(b,0,maxB+1) {
            int upto = a*coins[0] + b*coins[1];
            if (upto > n) break;

            if ((n - upto) % coins[2] == 0)
                return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
    
    return 0;
}

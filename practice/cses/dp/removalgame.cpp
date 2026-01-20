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
    vec<int> v(n);
    loop(i,0,n) cin>>v[i];

    int m = 0;
    loop(i,0,n) {
        int l,r, sca, scb;
        l=r=i;
        sca = scb = 0;

        bool aturn = n%2 == 1;

        while (!(l==0 && r==n-1)) {
            if (aturn) {
                
            } else {

            }


            aturn = !aturn;
        }
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
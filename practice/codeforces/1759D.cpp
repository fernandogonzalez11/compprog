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

int lastdigit(int n) {
    while (n%10==0) n /= 10;
    return n%10;
}

void solve() {
    int n,k;
    cin>>n>>k;

    array bestmults = {10, 10,5,10,5,2,5,10,5,10};

    int m = 1;
    while (m < k) {
        int ld = lastdigit(n*m);
        int bm = bestmults[ld];
        if (m*bm > k) {
            m *= (k/m);
            break;
        } else m *= bm;
    }

    cout << n*m << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

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

void solve() {
    int n,m;
    cin>>n>>m;
    if (!n&&!m) exit(0);
    bool reswap = n>m;
    if (n>m) swap(n,m);

    int amt;

    if (n==1) amt = max(n,m);
    else if (n==2) amt = (m/4)*4 + min(2LL,(m%4))*2;
    else {
        int rowA = m/2;
        int rowA_cnt = n/2 + (n%2);
        // * * *
        //  * *
        // * * *
        // ===
        // *****
        //
        // * * *
        amt = (m/2)*n + (m%2)*(n/2+(n%2));
    }

    if (reswap) swap(n,m);
    printf("%lld knights may be placed on a %lld row %lld column board.\n", amt, n, m);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (true) solve();
    
    return 0;
}

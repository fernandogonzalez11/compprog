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
    cin>>n;
    vec<int> v(n);

    int has05 = false;
    loop(i,0,n) {
        cin>>v[i];
        has05 |= v[i]%10==0;
        has05 |= v[i]%10==5;
    }

    if (has05) {
        // apply 1 operation -> all should be the same
        loop(i,0,n) v[i] += v[i]%10;
        loop(i,1,n)
            if (v[i] != v[i-1]) return false;
    }

    bool parity[] = {0,0,0,1,0,0,1,1,0,1};
    bool should = parity[v[0]%10] ^ ((v[0]/10)%2==0);
    loop(i,1,n) {
        bool is = parity[v[i]%10] ^ ((v[i]/10)%2==0);
        if (is != should) return false;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) cout << (solve() ? "Yes\n" : "No\n");
    
    return 0;
}

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
    int a, b, c;
    cin>>a>>b>>c;

    vec<int> whereto(101);
    loop(i,0,101) whereto[i] = i;

    loop(i,0,b) {
        int from,to;
        cin >> from >> to;
        whereto[from] = to;
    }

    vec<int> pos(a, 1);

    bool won = false;
    loop(i,0,c) {
        int roll;
        cin >> roll;
        if (won) continue;
        pos[i%a] = min(100LL, pos[i%a]+roll);
        pos[i%a] = whereto[pos[i%a]];
        won |= pos[i%a] == 100;
    }

    loop(i,0,a) {
        cout << "Position of player " << i+1 << " is " << pos[i] << ".\n";
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

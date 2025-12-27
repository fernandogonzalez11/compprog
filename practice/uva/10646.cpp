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

int val(string s) {
    if (s[0] >= '0' && s[0] <= '9') return s[0]-'0';
    return 10;
}

string solve() {
    array<string, 52> all;
    loop(i,0,52) cin >> all[i];

    int top = 52-1-25, topOg = top;
    int y = 0;
    loop(_,0,3) {
        int x = val(all[top]);
        y += x;
        top = top-1-(10-x);
    }

    if (--y > top) y = topOg + y-top;
    return all[y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    loop(i,1,t+1) cout << "Case " << i << ": " << solve() << "\n";
    
    return 0;
}

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

int mergeA(string s) {
    int n = s.size();
    vec<int> aAppearances;

    loop(i,0,n)
        if (s[i]=='a') aAppearances.push_back(i);

    int m = aAppearances.size();

    if (m == n || m == 0) {
        return 0;
    }

    int medI = (m-1)/2;
    int dist = 0;
    loop(i,0,m) dist += abs(aAppearances[medI]-aAppearances[i]);

    int lAmt = max(0LL,(medI-1)-(0)+1), rAmt = max(0LL,(m-1)-(medI+1)+1);
    // cout << m << medI << lAmt << rAmt << "\n";
    // cout << dist << "\n";
    dist -= lAmt*(lAmt+1)/2;
    dist -= rAmt*(rAmt+1)/2;

    return dist;
}

void solve() {
    int n;
    string s;

    cin >> n >> s;

    int dist = mergeA(s);
    loop(i,0,n) {
        if (s[i]=='a') s[i]='b';
        else s[i]='a';
    }

    dist = min(dist, mergeA(s));
    cout << dist << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

// a__a_a___a_
// ___aaaa____
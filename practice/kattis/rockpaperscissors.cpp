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

int rps(string s) {
    if (s == "paper") return 0;
    else if (s == "rock") return 1;
    else return 2;

    // 0 > 1 > 2 > 0
}

int game(string p1, string p2) {
    int ip1 = rps(p1);
    int ip2 = rps(p2);

    if (ip1==ip2) return 0;

    return ((ip1+1)%3 == ip2) ? 1 : 2;
}

void solve() {
    int n,k;
    cin>>n;

    if (!n) exit(0);
    cin>>k;

    int games = k * n*(n-1)/2;

    vec<int> lost(n,0), won(n,0);

    loop(_,0,games) {
        int p1,p2;
        string m1,m2;
        cin>>p1>>m1>>p2>>m2;
        p1--,p2--;
        int igame = game(m1,m2);
        if (igame == 1) {
            won[p1]++;
            lost[p2]++;
        } else if (igame == 2) {
            won[p2]++;
            lost[p1]++;
        }
    }

    loop(i,0,n) {
        int tot = won[i]+lost[i];
        if (!tot) cout << "-\n";
        else cout << fixed << setprecision(3) <<
            (double)won[i]/(won[i]+lost[i]) << "\n";
    }

    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (true) solve();
    
    return 0;
}

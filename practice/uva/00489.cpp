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
    int n;
    cin >> n;

    if (n==-1) exit(0);

    string a,b;
    cin>>a>>b;

    set<char> aset(a.begin(),a.end()),
              bset(b.begin(),b.end());

    array<int,26> firstPos;
    fill(firstPos.begin(),firstPos.end(),-1);
    loop(i,0,b.size())
        if (firstPos[b[i]-'a']==-1) firstPos[b[i]-'a'] = i;

    cout << "Round " << n << "\n";

    int won=0, lost=0;
    loop(i,0,b.size()) {
        int c = b[i];
        if (i>firstPos[c-'a']) continue;
        if (!aset.count(c)) lost++;
        else won++;

        if (lost == 7) {
            cout << "You lose.\n";
            return;
        } else if (won == aset.size()) {
            cout << "You win.\n";
            return;
        }
    }

    cout << "You chickened out.\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (true) solve();

    return 0;
}

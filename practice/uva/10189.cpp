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

void solve(int t) {
    int n,m;
    cin>>n>>m;
    if (!n&&!m) exit(0);

    if (t>1) cout << "\n";
    cout << "Field #" << t << ":\n";

    vec<vec<bool>> v(n, vec<bool>(m));
    {
        char c;
        loop(i,0,n)
            loop(j,0,m) {
                cin >> c;
                v[i][j] = c=='*';
            }
    }

    loop(i,0,n) {
        loop(j,0,m) {
            if (v[i][j]) cout << "*";
            else {
                int amt = 0;
                if (i>0) amt += v[i-1][j];
                if (i<n-1) amt += v[i+1][j];
                if (j>0) amt += v[i][j-1];
                if (j<m-1) amt += v[i][j+1];
                if (i>0&&j>0) amt += v[i-1][j-1];
                if (i>0&&j<m-1) amt += v[i-1][j+1];
                if (i<n-1&&j>0) amt += v[i+1][j-1];
                if (i<n-1&&j<m-1) amt += v[i+1][j+1];

                cout << amt;
            }
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (true) solve(t++);
    
    return 0;
}

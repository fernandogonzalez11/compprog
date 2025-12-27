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

int solve() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if (!a&!b&!c&!x&!y) exit(0);

    if (a>b) swap(a,b);
    if (a>c) swap(a,c);
    if (b>c) swap(b,c);
    if (x>y) swap(x,y);

    // lowest with highest
    array<int,3> fC = {x<a,x<b,x<c};
    array<int,3> sC ={y<a,y<b,y<c};
    int maxlosses = 0;
    loop(i,0,3) {
        loop(j,0,3) {
            if (i==j) continue;
            maxlosses = max(maxlosses,fC[i]+sC[j]);
        }
    }
    
    if (maxlosses == 2) return -1;
    int MC = 1;
    if (fC[0]) MC = max({MC,b+1,c+1});
    if (fC[1]) MC = max({MC, a+1, c+1});
    if (fC[2]) MC = max({MC, a+1, b+1});
    while (MC==a || MC==b || MC==c || MC==x || MC==y) MC++;
    if (MC > 52) return -1;

    return MC;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (true) cout << solve() << "\n";
    
    return 0;
}

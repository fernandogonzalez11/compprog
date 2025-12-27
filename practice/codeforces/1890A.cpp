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
    cin>>n;
    vec<int> v(n);
    loop(i,0,n) cin>>v[i];

    map<int,int> m;
    loop(i,0,n) m[v[i]]++;

    bool worked = m.size() == 1;
    if (m.size()==2) {
        vec<int> vv;
        for (auto [k,v] : m) vv.push_back(k);
        if (n&1) worked |= (m[vv[0]]-1==m[vv[1]] | m[vv[1]]-1==m[vv[0]]);
        else worked |= (m[vv[0]]==m[vv[1]]);
    }

    // loop(i,1,n-1) {
    //     vec<bool> vis(n,false);
    //     int k = v[0]+v[i];
    //     vis[0]=vis[i]=true;

    //     loop(j,1,n-1) {
    //         if (vis[i]) continue;
    //         loop(k,i+1,n) {
    //             if (vis[k]) continue;
    //             if (v[i]+v[k]!=k) continue;
    //             vis[i]=vis[k]=true;
    //             break;
    //         }   
    //     }

    //     printarr(vis);
    //     bool workedlocal = true;
    //     loop(j,0,n) workedlocal &= vis[j];
    //     worked |= workedlocal;
    // }

    cout << (worked?"Yes\n":"No\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

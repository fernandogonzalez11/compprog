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

int getmovesto0(vec<int> &v, set<int> &vset, vec<int> &vdiff) {
    if (vset.size()<v.size()) return 1;
    bool diffinv = false;
    for (auto val : vdiff) diffinv |= binary_search(v.begin(),v.end(),val);
    return (diffinv ? 2 : 3);
}

void solve() {
    int n,k;
    cin>>n>>k;

    vec<int> v(n);
    loop(i,0,n) cin>>v[i];
    sort(v.begin(),v.end());

    set<int> vset(v.begin(),v.end());
    vec<int> vdiff(n-1);
    loop(i,1,n) vdiff[i-1] = v[i]-v[i-1];
    sort(vdiff.begin(),vdiff.end());

    int movesto0 = getmovesto0(v,vset,vdiff);
    // cout<<movesto0<<"\n";

    if (k>=movesto0) cout << 0 << "\n";
    else {
        // <= 3, just simulate
        int m = min(v[0],vdiff[0]);
        if (k>1) {
            for (int i = 0; i < n-1; i++)
                for (int j = i+1; j < n; j++) {
                    // O(n²logn)
                    int val = abs(v[j]-v[i]);
                    int nexti = upper_bound(v.begin(),v.end(),val)-v.begin();
                    // cout << nexti << " ";
                    m = min(m, abs(v[nexti]-val));
                    if (nexti>0) m = min(m, abs(v[nexti-1]-val));
                }
        }
        // cout << "\n";
        cout<<m<<"\n";
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

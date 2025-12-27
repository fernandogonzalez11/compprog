#include <algorithm>
#include <bits/stdc++.h>
#include <string>

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

struct cave {
    // vector<int> v;
    int m;
    int n;

    cave() {}
    
    cave(vector<int> _v) {
        // v = _v;
        m = *max_element(_v.begin(),_v.end());
        n = _v.size();
    }

    bool operator<(cave &other) {
        return m < other.m;
    }
};

vec<cave> v;

bool ok(int P) {
    loop(i,0,v.size()) {
        if (v[i].m >= P) return false;
        P += v[i].n;
    }
    return true;
}

int solve() {
    int n;
    cin >> n;
    v.clear();
    v.resize(n);

    loop(i,0,n) {
        int k;
        cin >> k;
        vec<int> vv(k);
        loop(j,0,k) {
            cin >> vv[j];
            vv[j] -= j;
        }
        v[i] = cave(vv);
    }

    sort(v.begin(),v.end());

    int l = 0, r = 1;
    if (ok(l)) return l;
    while (!ok(r)) r *= 2;
    while (r-l>1) {
        int m = (r-l)/2+l;
        if (ok(m)) r = m;
        else l = m;
    }

    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) cout<<solve()<<"\n";
    
    return 0;
}

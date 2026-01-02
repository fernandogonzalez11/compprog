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

const int N = 1e6+10;
// vec<int> crib(N+2);

// void docrib() {
//     for (int i = 1; i <= N; i++) crib[i] = i;
//     for (int i = 2; i * i <= N; i++) {
//         if (crib[i] == i) {
//             for (int j = i * i; j <= N; j += i) crib[j] = i;
//         }
//     }
// }

// vec<int> divisors(int n) {
//     vec<int> d;

//     int a = n;
//     while (a > 1) {
//         d.push_back(a);
//         d.push_back(n/a);
//         a /= crib[a];
//         cout << a << "\n";
//     }

//     sort(d.begin(), d.end());
//     return d;
// }

vec<int> divisors(int n) {
    vec<int> d = {1,n};
    for (int i = 2; i * i <= n; i++) {
        if (n%i==0) {
            d.push_back(i);
            if (i * i != n) d.push_back(n/i);
        }
    }

    sort(d.begin(), d.end());
    return d;
}

int mex26(vec<int> &v) {
    vec<bool> has(26,false);
    for (auto u : v) has[u] = true;
    loop(i,0,26)
        if (!has[i]) return i;

    // shouldnt happen
    return -1;
}

void solve() {
    int n;
    cin >> n;

    vec<int> divs = divisors(n);
    // printarr(divs);

    vec<int> choices(n);
    choices[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        vec<int> shares;
        for (auto d : divs) {
            if (i+d >= n) break;
            shares.push_back(choices[i+d]);
        }
        choices[i] = mex26(shares);
    }

    loop(i,0,n) cout << (char)('a'+choices[i]);
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // docrib();
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

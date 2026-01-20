#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

const int BITS = 32;
int nums[BITS][BITS];
// nums[msb][set];
// all at 0 initially

void calc() {
    nums[0][0] = nums[0][1] = 1;
    loop(msb, 1, BITS) {
        loop(set, 1, BITS) {
            int val = 0;
            loop(msbi, 0, msb) {
                val += nums[msbi][set-1];
            }
            nums[msb][set] = val;
        }
    }

    // loop(i,0,BITS) {
    //     vec<int> vv(nums[i],nums[i]+BITS);
    //     printarr(vv);
    // }
}

void solve() {
    int n,k;
    cin>>n>>k;

    int cantdo = 0;
    // steps(n) = 2*set(n) + unset(n) - 1;
    loop(set,1,BITS) {
        loop(unset,0,BITS) {
            if (set+unset > n) continue;

            int steps = 2*set + unset - 1;
            if (steps > k) {
                cantdo += nums[set+unset][set];
            }
        }
    }

    cout << cantdo << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    calc();

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
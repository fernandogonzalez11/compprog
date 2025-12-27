#include <bits/stdc++.h>
#include <cmath>

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

int guess,onplace,offplace;

vec<int> intlist(int x) {
    vec<int> v;
    while (x) {
        v.push_back(x%10);
        x /= 10;
    }
    // reverse(v.begin(),v.end());
    return v;
}

bool check(vec<int> &vguess, vec<int> &vans) {
    map<int,int> anscnt;
    for (int u : vans) anscnt[u]++;

    int onpl = 0, offpl = 0, wrong = 0;

    loop(i,0,vguess.size()) {
        if (vguess[i] == vans[i]) {
            anscnt[vguess[i]]--;
            onpl++;
        }
    }

    loop(i,0,vguess.size()) {
        if (vguess[i] == vans[i]) continue;
        
        if (anscnt[vguess[i]]>0) {
            anscnt[vguess[i]]--;
            offpl++;
        } else wrong++;
    }

    // cout << onpl<<offpl<<wrong<<"\n";
    return onplace==onpl && offplace==offpl;
}

void solve() {
    cin>>guess>>onplace>>offplace;

    auto vguess = intlist(guess);

    int amt = 0;

    int guessdigs = vguess.size();
    for (int i = pow(10, guessdigs-1); i < pow(10, guessdigs); i++) {
        auto vans = intlist(i);
        bool has0 = false;
        for (auto u : vans) has0 |= (u==0);
        if (has0) continue;

        amt += check(vguess, vans);
    }

    cout << amt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

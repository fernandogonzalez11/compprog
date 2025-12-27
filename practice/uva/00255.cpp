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

pair<int,int> getCoords(int u) {
    int r = u/8;
    int c = u%8;
    return {r,c};
}

bool canKingBeHere(int k, pair<int,int> pq) {
    pair<int,int> pk = getCoords(k);
    return !(pk.F == pq.F || pk.S == pq.S);
}

bool solve() {
    int k,q,m;
    if (!(cin>>k>>q>>m)) return false;

    if (k == q) cout << "Illegal state";
    else if (q == m || k == m) cout << "Illegal move";
    else {
        pair<int,int> pk,pq,pm;
        pk = getCoords(k);
        pq = getCoords(q);
        pm = getCoords(m);

        // cout << pk.F << pk.S << " " << pq.F << pq.S << " " << pm.F << pm.S << "\n";

        if (!(pq.F == pm.F || pq.S == pm.S)) cout << "Illegal move";

        // same row
        else if (pk.F==pq.F && pk.F==pm.F && ((pk.S < pq.S) ^ (pk.S < pm.S))) cout << "Illegal move";
        else if (pk.S == pq.S && pk.S==pm.S && ((pk.F < pq.F) ^ (pk.F < pm.F))) cout << "Illegal move";
        else if ((pm.S == pk.S && abs(pm.F-pk.F) <= 1) || (pm.F == pk.F && abs(pm.S-pk.S) <= 1)) cout << "Move not allowed";
        else {
            vector<int> moves;
            if (pk.F != 0) moves.push_back(k-8);
            if (pk.F != 7) moves.push_back(k+8);
            if (pk.S != 0) moves.push_back(k-1);
            if (pk.S != 7) moves.push_back(k+1);

            bool can = false;
            for (auto a : moves) can |= canKingBeHere(a, pm);
            cout << (can ? "Continue" : "Stop");
        }      
    }

    cout << "\n";

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (solve());
    
    return 0;
}

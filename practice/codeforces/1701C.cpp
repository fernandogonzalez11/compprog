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

int ceil(int a, int b) {
    return a/b + (a%b>0);
}

// void solve() {
//     int n,m;
//     cin>>n>>m;

//     vec<int> T(n,0);
//     loop(i,0,m) {
//         int x;
//         cin>>x;
//         T[x-1]++;
//     }
//     sort(T.begin(),T.end());
//     // printarr(T);

//     int h = 0, t = 0;
//     loop(i,0,n-1) {
//         // int q = ceil(T[i], 2+h);
//         // t += q * 2;
//         // T[i] -= q * (2+h);

//         int q = T[i] / (2+h);
//         t += q * 2;
//         T[i] %= (2+h);
        

//         // normal behavior
//         T[i+1] -= q * 2;
//         // negative or 0 so it'll decrease
//         T[i+1] += T[i];
//         // T[i] = 0;
//         h++;
//     }

//     // printarr(T);
//     // cout << t << " " << h << "\n";

//     // for the last one...
//     int q = T[n-1] / (2+h);
//     t += q * 2;
//     T[n-1] %= (2+h);
//     if (T[n-1]==1) t += 1;
//     else if (T[n-1]>1) t += 2;

//     cout << t << "\n";
// }

void solve() {
    int n,m;
    cin>>n>>m;

    vec<int> T(n,0);
    loop(i,0,m) {
        int x;
        cin>>x;
        T[x-1]++;
    }

    auto ok = [&](int t) -> bool {
        int tasks_left = 0;
        int extra_tasks = 0;

        loop(i,0,n) {
            // tasks that take 1 hour
            int tasks_done = min(T[i], t);
            int seconds_left = t-tasks_done;

            tasks_left += T[i]-tasks_done;
            // extra tasks that take 2 hours
            extra_tasks += seconds_left/2;
        }

        return extra_tasks >= tasks_left;
    };

    int l = 0, r = 1;
    while (!ok(r)) r *= 2;
    while (r-l>1) {
        int m = (r-l)/2+l;
        // FFFVVVVVVV
        if (ok(m)) r = m;
        else l = m;
    }

    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

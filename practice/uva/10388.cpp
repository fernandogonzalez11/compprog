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

void putOnTop(deque<char> &onBottom, deque<char> &onTop) {
    while (!onTop.empty()) {
        char v = onTop.back();
        onTop.pop_back();
        onBottom.push_front(v);
    }
}

void changePile(deque<char> &down, deque<char> &up) {
    while (!up.empty()) {
        char v = up.back();
        up.pop_back();
        down.push_back(v);
    }
}

void solve() {
    deque<char> downa, downb, upa, upb;
    string a,b;
    cin >> a >> b;

    // top ....... bottom
    for (auto x : a) downa.push_back(x);
    for (auto x : b) downb.push_back(x);

    loop(_,0,1000) {
        char ca = downa.front(), cb = downb.front();
        downa.pop_front();
        downb.pop_front();
        upa.push_front(ca);
        upb.push_front(cb);

        if (ca==cb) {
            if (random()/141%2 == 0) {
                cout << "Snap! for Jane: ";
                putOnTop(upa, upb);

                for (auto x : upa) cout << x;
                cout << "\n";
            } else {
                cout << "Snap! for John: ";
                putOnTop(upb, upa);

                for (auto x : upb) cout << x;
                cout << "\n";
            }
        }

        if (upa.size()+downa.size() == 0) {
            cout << "John wins.\n";
            return;
        } else if (upb.size()+downb.size() == 0) {
            cout << "Jane wins.\n";
            return;
        }

        if (downa.empty()) changePile(downa, upa);
        if (downb.empty()) changePile(downb, upb);
    }

    cout << "Keeps going and going ...\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        scanf("\n");
        solve();
        if (t) cout << "\n";
    }
    
    return 0;
}

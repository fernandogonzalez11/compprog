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

int n, k, x;
vec<int> pos;

using interval = array<int,2>;

bool isempty(array<interval,2> x) {
	return (
		x[0][0] == -1 &&
		x[0][1] == -1 &&
		x[1][0] == -1 &&
		x[1][1] == -1
	);
}

bool isemptyint(interval i) {
	return i[0] == -1 && i[1] == -1;
}

array<interval,2> sintersection(array<interval,2> a, array<interval,2> b) {
	array<array<int,2>,2> empty;
	empty[0] = empty[1] = {-1,-1};

	if (isempty(a)) return empty;
	if (isempty(b)) return empty;
	
	vector<interval> res;
    for (auto &xa : a)
        for (auto &xb : b) {
            int L = max(xa[0], xb[0]);
            int R = min(xa[1], xb[1]);
            if (L <= R) res.push_back({L, R});
        }

	if (res.empty()) res.push_back({-1,-1});
	if (res.size() == 1) res.push_back({-1,-1});
	// cout << "sint:" << res.size() << "\n";
    return {res[0], res[1]};
}

array<interval,2> posToInterval(int pos, int d) {
	array<interval,2> res;
	if (pos-d < 0) res[0] = {-1,-1};
	else res[0] = {0, pos-d};

	if (pos+d > x) res[1] = {-1,-1};
	else res[1] = {pos+d, x};

	return res;
}

array<array<int,2>, 2> finalres;

bool ok(int d) {
	array<array<int,2>, 2> elem1, elem2;
	elem1 = posToInterval(pos[0], d);

	// for (auto p : elem1)
	// 		cout << "{"<<p[0]<<","<<p[1]<<"}, "; cout << "\n";

	loop(i,1,n) {
		elem2 = posToInterval(pos[i], d);

		elem1 = sintersection(elem1, elem2);

		// for (auto p : elem1)
		// 	cout << "{"<<p[0]<<","<<p[1]<<"}, "; cout << "\n";
	}

	// for (auto p : elem1)
	// 		cout << "{"<<p[0]<<","<<p[1]<<"}, "; cout << "\n";

	int amt = 0;
	amt += isemptyint(elem1[0]) ? 0 : elem1[0][1]-elem1[0][0]+1;
	amt += isemptyint(elem1[1]) ? 0 : elem1[1][1]-elem1[1][0]+1;

	finalres = elem1;
	return amt >= k;
}

vec<int> pick_k() {
    vec<int> res;
    for (auto &iv : finalres) {
        if (iv[0] == -1) continue;
        for (int x = iv[0]; x <= iv[1] && (int)res.size() < k; ++x)
            res.push_back(x);
        if ((int)res.size() == k) break;
    }
    return res;
}

void solve() {
	cin >> n >> k >> x;
	pos.resize(n);
	pos.clear();
	loop(i,0,n) cin >> pos[i];
	
	int l = 0, r = 1;
	// VVVVVFFFFFF
	while (ok(r)) r *= 2;
	while (r-l > 1)	 {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	int val = l;

	cout << val << "\n";

	ok(val);

	for (auto p : finalres)
	 		cout << "{"<<p[0]<<","<<p[1]<<"}, "; cout << "\n";


	vec<int> vvvv = pick_k();

	printarr(vvvv);
	

	// cout << ok(0) << "\n";
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

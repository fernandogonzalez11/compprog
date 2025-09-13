#include <bits/stdc++.h>
#include <numeric>

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

const int MAX_N = 2e5 + 1;

// credit to https://cp-algorithms.com/sequences/mex.html
int mex(vector<int> const& A) {
    static bool used[MAX_N+1] = { 0 };

    // mark the given numbers
    for (int x : A) {
        if (x <= MAX_N)
            used[x] = true;
    }

    // find the mex
    int result = 0;
    while (used[result])
        ++result;

    // clear the array again
    for (int x : A) {
        if (x <= MAX_N)
            used[x] = false;
    }

    return result;
}

void oneOp(vec<int> &v) {
	// O(n)
	int n = v.size();
	vec<int> freq(n+1,0);
	loop(i,0,n) freq[v[i]]++;

	// O(n)
	int MEX = mex(v);
	loop(i,0,n) {
		if (freq[v[i]] > 1) v[i] = MEX;
		else v[i] = min(MEX, v[i]);
	}
}

void solve() {
    int n,k;
	cin >> n >> k;

	vec<int> v(n);
	loop(i,0,n) {
		cin >> v[i];
	}

	const int MAX_K = 4;

	// O(1000n)
	// gambling >>>>>> thinking
	if (k <= MAX_K) {
		loop(i,0,k) oneOp(v);
	} else {
		loop(i,0,MAX_K) oneOp(v);
		if (k%2 == 1) oneOp(v);
	}

	cout << accumulate(v.begin(), v.end(), 0) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

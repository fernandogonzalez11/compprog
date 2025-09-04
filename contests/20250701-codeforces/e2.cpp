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

vec<pair<int, int>> freqV;

int mex() {
	int res = 0;
	for (auto p : freqV) {
		if (p.F != res) return res;
		res++;
	}
	return res;
}

void solve() {
    int n;
	cin >> n;

	int n_copy = n;
	
	map<int, int> freq;

	loop(i,0,n) {
		int x;
		cin >> x;
		freq[x]++;
	}

	// num, freq
	freqV.assign(freq.begin(), freq.end());

	// for (auto p : freqV) {
	// 	cout << p.F << " " << p.S << "\n";
	// }

	n = freqV.size();

	unordered_map<int, int> freqVI;
	loop(i,0,n) freqVI[freqV[i].F] = i;

	vec<int> pref(n+1), suf(n+1);
	pref[0] = 0;
	loop(i,0,n) pref[i+1] = pref[i] + freqV[i].S;

	suf[n] = 0;
	for (int i = n-1; i >= 0; i--) suf[i] = suf[i+1] + freqV[i].S;

	// printarr(pref);
	// printarr(suf);
	
	int me = mex();
	vec<pair<int, int>> segments(me+1);
	loop(i,0,me+1) {
		// min amt i remove to get mex = i
		segments[i].F = freq[i];

		if (i != me) {
			int idx = freqVI[i];
			segments[i].S = freq[i] + suf[i+1] + pref[i] - idx;
		} else {
			// first value that is > x
			// FFFFVVV
			int l = 0, r = n-1;
			while (r-l>1) {
				int m = (r-l)/2+l;
				if (freqV[m].F > m) r = m;
				else l = m;
			}

			segments[i].S = suf[r+1] + pref[r] - r;
		}
	}

	// for (auto p : segments) {
	// 	cout << p.F << " " << p.S << "\n";
	// }

	vec<int> diff(n_copy+1, 0);
	for (auto p : segments) {
		diff[p.F]++;
		diff[p.S + 1]--;
	}

	int d = 0;
	loop(i,0,n_copy+1) {
		d += diff[i];
		cout << d << " ";
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

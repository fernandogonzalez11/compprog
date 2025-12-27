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

void solve() {
    int n;
	cin >> n;
	vec<int> v(2*n);
	map<int,int> freq;
	loop(i,0,2*n) {
		cin >> v[i];
		freq[v[i]]++;
	}
	// sort(v.begin(),v.end());

	// unique array construction but not really construction
	int amt(0);
	int sz = freq.size();
	for (auto p : freq) {
		if (p.S%2) amt += 1;
		else amt += 2;

		freq[p.F]--;
	}

	// cout << amt << "\n";

	int mustmove = (sz - (2*n-sz))/2;

	// cout << "mustmove:"<<mustmove << "\n";

	if (mustmove == 0) cout << amt << "\n";
	else if (mustmove>0) {
		for (auto p : freq) {
			if ((1+p.S)%2==0 || p.S==0) {
				mustmove--;
				freq[p.F]++;
			}
		}
		cout << amt-max(0LL,mustmove) << "\n";
	} else {
		for (auto p : freq) {
			if ((1+p.S)%2==1) {
				int shouldmove = min(-mustmove, p.S-1);
				mustmove += shouldmove;
				freq[p.F] -= shouldmove;
			} else {
				// doesnt change amt
				int shouldmove = min(-mustmove/2*2,(p.S-1)/2*2);
				// cout << "sh:"<<shouldmove << "\n";
				// cout << "mm:"<<mustmove << "\n";

				mustmove += shouldmove;
				// cout << "mm:"<<mustmove << "\n";

				freq[p.F] -= shouldmove;
			}
		}

		// cout << "f:" << mustmove << "\n";

		cout << amt-max(0LL, -mustmove)*2 << "\n";
		// cout << "what" << mustmove << "\n";
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

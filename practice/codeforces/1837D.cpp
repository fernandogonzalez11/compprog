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
#define printarr(a) /*cout << #a << ": ";*/ \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vec<int> choose(n);

	char firstchar = s[0];

	bool nsegment;
	bool existenceofoppositesegmentthatisnotassociatedwithfirstchar = false;
	int balance = 0;

	int i = 0;

	int amt = 0;

	while (i<n) {
		auto macro = [&]() {
			balance += (s[i]=='(' ? 1 : -1);
			choose[i] = nsegment+1;
			i++;
		};

		nsegment = s[i]!=firstchar;
		existenceofoppositesegmentthatisnotassociatedwithfirstchar |= nsegment;
		macro();
		while (i < n && balance != 0) macro();
	}


	if (balance != 0) cout << "-1\n";
	else {
		cout << (existenceofoppositesegmentthatisnotassociatedwithfirstchar ? 2 : 1) << "\n";
		printarr(choose);
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

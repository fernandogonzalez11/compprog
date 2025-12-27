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

// leading zeros, amount of digits
array<int,2> leadingZeros(int n) {
	if (n == 0) return {0,0};
	int zeros = 0;
	while (n % 10 == 0) {
		zeros++;
		n /= 10;
	}

	int nums = 0;
	while (n > 0) {
		nums++;
		n /= 10;
	}

	return {zeros, zeros+nums};
}

void solve() {
    int n, m; cin >> n >> m;

	int digAmt = 0;

	vec<int> leads(n);
	loop(i,0,n) {
		cin >> leads[i];
		array<int,2> a = leadingZeros(leads[i]);
		leads[i] = a[0];
		digAmt += a[1];
	}

	sort(leads.begin(), leads.end(), greater<>());

	// printarr(leads);

	int s = 0;
	for (int i = 0; i < n; i += 2) s += leads[i];

	if (digAmt - s >= m+1) cout << "Sasha\n";
	else cout << "Anna\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

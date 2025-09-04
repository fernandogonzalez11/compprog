#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

int main() {
	int n; string s; cin >> n >> s;

	vec<ll> ones;
	loop(i, 0, n)
		if (s[i] == '1') ones.push_back(i);

	if (ones.size() < 2) {
		cout << 0 << "\n";
		return 0;
	}

	// make prefs
	ll os = ones.size();
	vec<ll> prefs(os);

	prefs[0] = ones[0];
	loop(i, 1, os)
		prefs[i] = prefs[i - 1] + ones[i];
	
	ll mintotal = INF;
	loop(i, 0, os) {
		ll totaldist = 0;
		if (i > 0) {
			const ll amt = i;
			totaldist += ones[i] * amt;
			totaldist -= prefs[i - 1];

			// then, remove 1 + 2 + ... amt
			totaldist -= amt * (amt + 1) / 2;
		}
		if (i < os - 1) {
			const ll amt = (os - 1) - i;
			totaldist += prefs[os - 1] - prefs[i];
			totaldist -= ones[i] * amt;

			totaldist -= amt * (amt + 1) / 2;
		}

		mintotal = min(mintotal, totaldist);
	}

	cout << mintotal << "\n";

	return 0;
}

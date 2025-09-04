#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF 1 << 30 + 1 << 25

using namespace std;


void proc() {
	int n; cin >> n;
	vec<int> v(n);
	loop(i, 0, n) cin >> v[i];

	vec<int> prefs(n);
	set<int> distinctmap;
	prefs[0] = 1;
	distinctmap.insert(v[0]);

	loop(i, 1, n) {
		int val = v[i];
		prefs[i] = prefs[i - 1] + !distinctmap.count(val);
		distinctmap.insert(val);
	}

	loop(i, 0, n) cout << prefs[i] << " ";
	cout << "\n";

	int total = n - prefs[n - 1];
	int gl = -1, gr = -1;

	loop(l, 0, n) {
		loop(r, 0, n) {
			int diff = (prefs[r] - prefs[l]) - (r - l);
			if (diff >= 0) {
				total += diff;
				gl = l; gr = r; 
			}
		}
	}

	cout << gl << " " << gr << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) proc();

	return 0;
}

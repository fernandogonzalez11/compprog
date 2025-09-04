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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vec<int> v(n);
	loop(i, 0, n) cin >> v[i];

	int totmax, locmax;
	totmax = locmax = v[0];

	loop(i, 1, n) {
		locmax = max(locmax + v[i], v[i]);
		totmax = max(totmax, locmax);
	}

	cout << totmax << "\n";

	return 0;
}

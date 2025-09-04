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

void process() {
	int n, m; cin >> n >> m;
	// for now, m = 1, so we only have to get one int
	vec<int> ns(n), ms(m);
	// choose: a[i] = -a[i] + b[j] or nothing
	loop(i, 0, n) {
		cin >> ns[i];
		// negate at once
		ns[i] = -ns[i];
	}
	loop(i, 0, m) cin >> ms[i];

	// with all negated already, we have two choices
	// 1: a[i] = -a[i]
	// 2: a[i] += b[j]
	// greedy: choose min between each two that is also >= than the last
	ns[0] = min(-ns[0], ns[0] + ms[0]);
	loop(i, 1, n) {
		int c1 = -ns[i], c2 = ns[i] + ms[0];
		int last = ns[i - 1];
		// if none make the increasing, we can't advance further
		if (!(c1 >= last || c2 >= last)) {
			cout << "NO" << "\n";
			return;
		}
		// if both do, lets choose the minimum
		else if (c1 >= last && c2 >= last) ns[i] = min(c1, c2);
		// if only one does, choose it through a multiplexor
		else ns[i] = (c1 >= last) * c1 + (c2 >= last) * c2;
	}

	// loop(i, 0, n) cout << ns[i] << " ";
	cout << "YES" << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) process();

	return 0;
}
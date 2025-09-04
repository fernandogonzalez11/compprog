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

int binsearch(const vec<int> &b, int last, int a) {
	int l = 0, r = b.size() - 1;
	while (l < r) {
		int mid = (r - l) / 2 + l;
		// prune right (excl. current)
		if (a + b[mid] >= last) r = mid;
		// prune left (incl. current)
		else l = mid + 1;
	}
	return l;
}

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
	// sort to do binsearch
	sort(ms.begin(), ms.end());

	// with all negated already, we have two choices
	// 1: a[i] = -a[i]
	// 2: a[i] += b[j]
	// greedy: choose min between each two that is also >= than the last

	// at the start, all are >= than the last, so use the min
	ns[0] = min(-ns[0], ns[0] + ms[0]);
	
	// then, since we have sorted, when we have P(x): ax + bi >= last, we'll get
	// b1 b2 b3 ... bm-1 bm
	// F  F  V  ... V    V
	// thus, search first V with binsearch
	loop(i, 1, n) {
		int last = ns[i - 1];
		int toAdd = ms[binsearch(ms, last, ns[i])];
		int c1 = -ns[i], c2 = ns[i] + toAdd;
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

#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)

// constants
#define INF 1 << 30 + 1 << 25

using namespace std;

void sufArr(string s) {
	s += "$";
	int n = s.size();

	vec<int> p(n), c(n);

	// initial step
	vec<pair<char, int>> a(n);
	// sort by char and put the placements in p
	loop(i, 0, n) a[i] = { s[i], i };
	sort(a.begin(), a.end());
	loop(i, 0, n) p[i] = a[i].second;
	// make equivalence classes
	c[p[0]] = 0;
	loop(i, 1, n) {
		int past = c[p[i - 1]];
		c[p[i]] = past + (a[i - 1].first != a[i].first);
	}

	// subsequent log(n) steps
	// transition from k -> k + 1
	// => string length 2^k -> 2^k+1
	int k = 0;
	while ((1 << k) < n) {
		vec<pair<pair<int, int>, int>> b(n);
		loop(i, 0, n)
			b[i] = {{ c[i], c[(i + (1 << k)) % n] }, i};
		
		sort(b.begin(), b.end());
		loop(i, 0, n) p[i] = b[i].second;

		// make equivalence classes
		c[p[0]] = 0;
		loop(i, 1, n) {
			int past = c[p[i - 1]];
			c[p[i]] = past + (b[i - 1].first != b[i].first);
		}

		k++;
	}

	loop(i, 0, n) cout << p[i] << " ";
}

int main() {
	string s;
	cin >> s;

	sufArr(s);

	return 0;
}

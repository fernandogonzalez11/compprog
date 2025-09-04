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

// ln2(2 * 10⁵) = 17.6
const int CRIBLEN = 1 << 18;
vec<bool> crib(CRIBLEN, true);

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}

void makeCrib() {
	crib[0] = crib[1] = false;
	for (int i = 2; i < CRIBLEN; i++) {
		if (!crib[i]) continue;
		for (int j = i + i; j < CRIBLEN; j += i)
			crib[j] = false;
	}
}

void process() {
	int n; cin >> n;
	vec<int> a(n);
	loop(i, 0, n) cin >> a[i];

	int count = 0;
	loop(i, 0, n) {
		// i <= j
		loop(j, i, n) {
			cout << a[i] << " " << a[j];
			// lcm(a, b) = (a * b) / gcd(a, b)
			// check if a/gcd(a, b) & b are primes or viceversa
			// divide the greatest one by the gcd
			int g = gcd(a[i], a[j]);
			// max and min
			// necessarily both can be divided by g
			int ma = max(a[i], a[j]);
			int mi = a[i] + a[j] - ma;
			// either 0 or 1
			count += (crib[ma / g] & crib[mi]);

			cout << " -> " << g << " " << a[i] / g * a[j] << " / "
				 << ma/g << " " << mi << ": " << crib[ma/g] << " " << crib[mi] << "\n";
		}
	}
	cout << count << "\n";
}

int main() {
	makeCrib();

	int t; cin >> t;
	while (t--) process();

	return 0;
}

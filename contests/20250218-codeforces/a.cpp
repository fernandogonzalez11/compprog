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

bool genarr(int n, vec<int> &b) {
	vec<int> a(n, -1);
	a[0] = 0;

	if (b[1]) a[1] = a[2] = a[0];
	else a[1] = a[2] = !a[0];

	loop(i, 2, n - 1) {
		if (b[i]) {
			if (a[i - 1] != a[i]) return false;
			a[i + 1] = a[i];
		} else {
			if (a[i - 1] == a[i]) a[i + 1] = !a[i];
			else a[i + 1] = a[i];
		} 
	}
	return true;
}

void proc() {
	int n; cin >> n;
	vec<int> b(n);
	loop(i, 1, n - 1) cin >> b[i];

	cout << (genarr(n, b) ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}

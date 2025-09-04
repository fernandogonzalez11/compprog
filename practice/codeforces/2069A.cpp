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
	for (int i = 0; i <= n-3; i++) {
        if (b[i] == 1 && b[i+1] == 0 && b[i+2] == 1) return false;
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
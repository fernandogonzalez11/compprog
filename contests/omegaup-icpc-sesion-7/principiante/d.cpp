#include <bits/stdc++.h>
#include <iomanip>

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
	double acc = 0;
	loop(i, 0, n) {
		int x; cin >> x;
		acc += x;
	}

	cout << fixed << setprecision(2) << acc / n << "\n";
	return 0;
}

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
	string c1, c2; cin >> c1 >> c2;
	bool b1 = c1 == "fine", b2 = c2 == "fine";

	cout << (
		(!b1 & !b2) * 1 +
		(!b1 & b2) * 2 +
		(b1 & !b2) * 3 +
		(b1 & b2) * 4
	) << "\n";

	return 0;
}

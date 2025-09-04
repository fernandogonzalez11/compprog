#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

vec<pair<int, int>> moves;

void transfer(int n, int start, int end) {
	if (n == 1)
		moves.push_back({ start, end });
	else {
		transfer(n - 1, start, 1+2+3 - start - end);
		moves.push_back({ start, end });
		transfer(n - 1, 1+2+3 - start - end, end);
	}
}

void hanoi(int n) {
    transfer(n, 1, 3);
	cout << moves.size() << "\n";
	for (auto p : moves)
		cout << p.F << " " << p.S << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n; cin >> n;
	hanoi(n);

	return 0;
}

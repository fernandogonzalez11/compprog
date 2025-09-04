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
	int n, m; cin >> n >> m;
	int cnt = 0;
	set<pair<int, int>> revs;

	loop(i, 0, m) {
		int v1, v2; cin >> v1 >> v2;
		if ((v1 == v2) | revs.count({v1, v2})) cnt++;
		else {
			revs.insert({v1, v2});
			revs.insert({v2, v1});
		}

	}

	cout << cnt << "\n";

	return 0;
}

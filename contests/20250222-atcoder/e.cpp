#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

int mins(vec<vec<pair<int, char>>> &g, int i, int j, stack<pair<int, char>> palcheck) {
	for (pair<int, char> p : g[i]) {
		palcheck.push(p);
		int res1 = mins(g, p.F, j, palcheck);
		palcheck.pop();
		int res2 = INF;
		if (palcheck.size()) {
			pair<int, char> p2 = palcheck.top();
			if (p2.S != p.S) res2 = min(res2, INF);
			palcheck.pop();
			res2 = min(res2, mins(g, p2.F, j, palcheck));
			palcheck.push(p2);
		}

		return min(res1, res2);
	}
	return INF;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vec<vec<pair<int, char>>> g(n);

	loop(i, 0, n) {
		string s; cin >> s;
		loop(j, 0, n) {
			g[i].push_back({j, s[j]});
		}
	}

	loop(i, 0, n) {
		loop(j, 0, n) {
			if (i == j) cout << 0 << " ";
			else {
				stack<pair<int, char>> pal;
				cout << mins(g, i, j, pal) << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}

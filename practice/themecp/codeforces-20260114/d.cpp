#include <algorithm>
#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) /*cout << #a << ": "; */\
	for (auto x : a) cout << x << " "; \
	cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

// https://codeforces.com/problemset/problem/2143/C
void solve() {
	int n;
	cin>>n;

	vec<array<int,4>> edges(n-1);
	loop(i,0,n-1) {
		cin>>edges[i][0]>>edges[i][1]>>edges[i][2]>>edges[i][3];
		edges[i][0]--;
		edges[i][1]--;
	}

	sort(all(edges), [](array<int,4> &a1, array<int,4> &a2) {
		int M1 = max(a1[2],a1[3]);
		int M2 = max(a2[2],a2[3]);
		int m1 = min(a1[2],a1[3]);
		int m2 = min(a2[2],a2[3]);
		return M1 > M2 || (M1 == M2 && m1 > m2);
	});

	// loop(i,0,n-1) {
	// 	auto vv = edges[i];
	// 	printarr(vv);
	// }


	vec<int> res(n, INF);
	res[edges[0][0]] = 0;
	int lo = -1, hi = 1;
	for (auto edge : edges) {
		int M = max(edge[2], edge[3]);
		int m = edge[2]+edge[3]-M;

		bool uhigher = M == edge[2];
		bool isu = res[edge[0]] != INF;
		bool isv = res[edge[1]] != INF;
		if (isu && isv) {
			// nada que hacer
		} else if (!isu && !isv) {
			if (uhigher) {
				res[edge[0]] = hi++;
				res[edge[1]] = lo--;
			} else {
				res[edge[0]] = lo--;
				res[edge[1]] = hi++;
			}
		} else if (!isu) {
			res[edge[0]] = (uhigher ? hi++ : lo--);
		} else if (!isv) {
			res[edge[1]] = (uhigher ? lo-- : hi++);
		}
	}

	// printarr(res);

	int dif = 1 - *min_element(all(res));
	loop(i,0,n) res[i] += dif;
	printarr(res);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

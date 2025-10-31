#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

int n, m;

int upperrow(vec<vec<bool>> v) {
	loop(i,0,n)
		loop(j,0,m) 
			if (v[i][j]) return i;

	return -1;
}

int leftcol(vec<vec<bool>> v) {
	loop(j,0,m)
		loop(i,0,n)
			if (v[i][j]) return j;

	return -1;
}

int lowerrow(vec<vec<bool>> v) {
	for (int i = n-1; i >= 0; i--)
		loop(j,0,m) 
			if (v[i][j]) return i;

	return -1;
}

int rightcol(vec<vec<bool>> v) {
	for (int j = m-1; j >= 0; j--)
		loop(i,0,n)
			if (v[i][j]) return j;

	return -1;
}

int cnt(vec<vec<bool>> v) {
	int c = 0;
	loop(i,0,n) loop(j,0,m) c += v[i][j];
	return c;
}

void solve() {
	cin >> n >> m;

	enum coords {
		Y,
		X
	};

	vec<vec<bool>> v(n, vec<bool>(m));
	loop(i,0,n)
		loop(j,0,m) {
			char x;
			cin >> x;
			v[i][j] = x == 'B';
		}

	int up = upperrow(v), down = lowerrow(v),
		left = leftcol(v), right = rightcol(v);

	// cout << up << down << left << right << "\n";

	if (up == -1) {
		cout << "1\n";
		return;
	}

	int sqSide = max({
		down-up,
		right-left
	}) + 1;

	if (sqSide > n || sqSide > m) {
		cout << "-1\n";
		return;
	}

	int c = cnt(v);

	cout << sqSide*sqSide-c << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}

#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
	for (auto x : a) cout << x << " "; \
	cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin>>n;
	string s;
	cin>>s;

	vec<bool> can(n,true);

	int l = 0, r = n-1;
	for (; l < n; l++) {
		if (s[l]=='1') break;
		can[l] = false;
	}

	for (; r >= 0; r--) {
		if (s[r]=='0') break;
		can[r] = false;
	}

	if (!(l<r)) {
		cout << "Bob\n";
		return;
	}

	// starts with 1 segment
	vec<pii> segments;
	segments.push_back({0,1});
	for (int i = l+1; i <= r; i++) {
		if (s[i]==s[i-1]) segments[segments.size()-1].S++;
		else {
			segments.push_back({i,1});
		}
	}

	// for (auto [a,b] : segments) cout << a << " " << b << "\n";

	int x = segments[1].S;
	for (int i = 3; i < segments.size(); i += 2) {
		x ^= segments[i].S;
	}

	if (x==0) {
		cout << "Bob\n";
		return;
	}

	deque<int> move;

	for (int i = 1; i < segments.size(); i += 2) {
		int rm = segments[i].S ^ x;
		if (rm < segments[i].S) {
			int take = segments[i].S - rm;
			if (take == 0) take = segments[i].S;
			loop(j,0,take) move.push_back(segments[i].F+j);
			move.push_front(segments[i-1].F);
			break;
		}
	}

	cout << "Alice\n";
	cout << move.size() << "\n";
	loop(i,0,move.size()) cout << move[i]+1 << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

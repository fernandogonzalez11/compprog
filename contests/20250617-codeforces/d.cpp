#include <bits/stdc++.h>
#include <functional>
#include <unordered_map>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
	vec<int> a(n), b(n);
	unordered_map<int, int> posA, posB;

	{
		int x;
		loop(i,0,n) {
			cin >> x;
			a[i] = x;
			posA[x] = i;
		}
		loop(i,0,n) {
			cin >> x;
			b[i] = x;
			posB[x] = i;
		}
	}

	vec<int> aS = a, bS = b;
	sort(aS.begin(), aS.end(), greater<>());
	sort(bS.begin(), bS.end(), greater<>());
	
	vec<pair<int, int>> ops;
	loop(i,0,n-1) {
		// need to carry i to position n-1-i
		// both in a and b
		// cout << aS[i] << "\n";
		int posI = posA[aS[i]];
		// cout << "p" << posI << "\n";
		loop(j, posI, (n-1)-i) {
			// cout << "picked " << a[j] << " " << a[j+1] << "\n";
			// cout << posA[5] << "\n";
			posA[a[j]]++;
			posA[a[j+1]]--;
			a[j] ^= a[j+1];
			a[j+1] ^= a[j];
			a[j] ^= a[j+1];

			ops.push_back({1,j+1});
		}

		posI = posB[bS[i]];
		loop(j, posI, (n-1)-i) {
			posB[b[j]]++;
			posB[b[j+1]]--;
			b[j] ^= b[j+1];
			b[j+1] ^= b[j];
			b[j] ^= b[j+1];

			ops.push_back({2, j+1});
		}
	}

	loop(i,0,n) {
		if (a[i] > b[i]) {
			ops.push_back({3, i+1});
			a[i] ^= b[i];
			b[i] ^= a[i];
			a[i] ^= b[i];
		}
	}

	// loop(i,0,n) cout << a[i] << " "; cout << "\n";
	// loop(i,0,n) cout << b[i] << " "; cout << "\n";

	cout << ops.size() << "\n";
	for (auto p : ops) cout << p.F << " " << p.S << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

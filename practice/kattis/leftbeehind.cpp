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

string solve(int x, int y) {
	if (x+y == 13) return "Never speak again.";
	if (x==y) return "Undecided.";
	if (x>y) return "To the convention.";
	return "Left beehind.";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	while (true) {
		int x,y;
		cin >> x >> y;

		if (x == 0 && y == 0) return 0;
		cout<<solve(x, y)<<"\n";
	}

	return 0;
}

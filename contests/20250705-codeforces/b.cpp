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

bool solve() {
    int n;
	double px, py, qx, qy;
	cin >> n >> px >> py >> qx >> qy;

	vec<int> a(n);
	int S = 0;
	loop(i,0,n) {
		cin >> a[i];
		S += a[i];
	}

	cout << S << "\n";

	int D = (qx - px) * (qx - px) + (qy - py) * (qy - py);
	int actual_S = S;
	S = S * S;

	if (S < D) return false;
	// equal => just choose the straight line
	else if (S == D) return true;
	else {
		// can i make a polygon with sides a1, a2, ..., an, d?
		double Dd = sqrt((double) D);
		cout << Dd << "\n";
		

		S = actual_S;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "Yes\n" : "No\n");

	return 0;
}

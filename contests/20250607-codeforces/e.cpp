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

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

bool solve() {
    int n;
	cin >> n;
	vec<int> p(n), s(n);
	loop(i,0,n) cin >> p[i];
	loop(i,0,n) cin >> s[i];

	if (n == 1) return (p[0] == s[0]);

	vec<int> posP(n), posS(n), pos(n, -1);
	posP[0] = p[0];
	posS[n-1] = s[n-1];

	int g = p[0];
	loop(i,1,n) {
		if (!(g % p[i] == 0)) return false;
		g = p[i];
		
		if (p[i] == p[i-1]) {
			posP[i] = -1;
		}
		else {
			posP[i] = g;
		}
	}

	g = s[n-1];
	// careful: arr can be of 1 elem!
	for (int i = n-2; i >= 0; i--) {
		if (!(g % s[i] == 0)) return false;
		g = s[i];
		
		if (s[i] == s[i+1]) {
			posS[i] = -1;
		}
		else {
			posS[i] = g;
		}
	}
	

	loop(i,0,n) {
		if (posP[i] == -1 && posS[i] == -1) {
			// nothing: we'll skip
		} else if (posP[i] == -1) {
			pos[i] = posS[i];
		} else if (posS[i] == -1) {
			pos[i] = posP[i];
		} else {
			if (posP[i] != posS[i]) return false;
		}
	}

	// printarr(p);
	// printarr(s);
	// printarr(pos);

	g = pos[0];
	loop(i,1,n) {
		if (pos[i] == -1) g = p[i];
		else g = gcd(g, pos[i]);
		if (g != p[i]) return false;
	}

	g = pos[n-1];
	for (int i = n-2; i >= 0; i--) {
		if (pos[i] == -1) g = s[i];
		else g = gcd(g, pos[i]);
		if (g != s[i]) return false;
	}

	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}

#include <bits/stdc++.h>
#include <cstdio>

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

/*

1. swap 0->1 with 1->0
2. 

*/

void solve(int I) {
    string s,t;
	cin>>s>>t;

	int n = s.length();

	int z2o = 0, o2z = 0, q0 = 0, q1 = 0, amt = 0;
	loop(i,0,n) {
		if (s[i]=='0' && t[i]=='1') z2o++;
		else if (s[i]=='1' && t[i]=='0') o2z++;
		else if (s[i]=='?') {
			if (t[i] == '0') q0++;
			else q1++;
		}
	}

	if (z2o+q10.333
0.667

0.000
1.000
 < o2z) {
		amt = -1;
	} else {
		int dif = min(z2o, o2z);
		z2o -= dif;
		o2z -= dif;
		amt += dif; // swap

		dif = min(o2z, q1);
		o2z -= dif;
		q1 -= dif;
		amt += 2*dif; // init + swap

		amt += q0+q1;
		amt += z2o;
	}

	printf("Case %lld: %lld\n", I, amt);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	loop(i,1,t+1) solve(i);

	return 0;
}

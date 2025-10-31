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
#define printarr(a) /*cout << #a << ": ";*/ \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
    int n;
	cin >> n;

	if (n==1) {
		cout << "1 1\n";
		return;
	}

	vec<int> v(2*n,-1);
	
	loop(i,0,n) v.at(2*n-1-i) = i+1;
	swap(v.at(2*n-1), v.at(2*n-2));
	// printarr(v);

	int a = n;
	for (int i = 0; i < n; i += 2) {
		v.at(i) = a--;
	}

	for (int i = n-1-(n%2==1); i >= 0; i -= 2) {
		v.at(i) = a--;
	}

	{
		int at1 = -1, at2 = -1;
		loop(i,0,n) {
			if (v.at(i)==1) at1 = i;
			else if (v.at(i)==2) at2 = i;
		}
		swap(v.at(at1), v.at(at2));
	}

	// printarr(v);
	// cout << "---\n";

	// int j = n;
	// for (int i = 2*n-1; i >= n; i -= 2) {
	// 	v.at(i) = j;
	// 	v.at(i-1) = n-j+1;
	// 	j--;
	// }

	// if (n >= 2) {
	// 	swap(v.at(2*n-2), v.at(2*n-4));
	// }
	// printarr(v);

	printarr(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

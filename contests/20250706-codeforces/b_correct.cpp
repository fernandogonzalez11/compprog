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

void solve() {
    int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	// obs: if we make everything 0 from j onwards we "truncate" the sum upto j-1
	// obs: we should be making as much 0s as we can
	// hyp: 0 with 1?
	// a b c d
	// a + b 0 0 0
	// obs: sum is at least a (we can't get rid of it)
	// at most a+n (upper bound is n)
	// 4 3 2 1 -> 10
	// 7 0 0 0
	// we pretty much collapsed 4 and 3 into 1, and removed everything else
	// 1 2 3 4 5 -> 5
	// 3 0 0 0 0 -> 2
	// this doesnt work, the best is doing 2+3 0 0
	// why?
	// since 1 < 2, prefix min will be 1+1 (instead of 1+2)
	// but here we're collapsing 1+2 so prefix min will be (1+2)+0+0.....
	// ok so try 1 with 2
	// 1 2 3 4 5
	// 1 5 0 0 0
	// 1 1 0 0 0
	// 2
	// if a1 < a2
	// you know it doesnt actually matter what the result of a2+a3 is
	// because the prefix min will always be a1
	// or really a2 + anything will happen this
	
	// so if a > b just straight up make
	// a+b 0 0 0 0....
	// result would be a+b <= original

	// if a < b
	// i do
	// a b+fucking anything 0 0 0 0....
	// which turns the sum into
	// a+a

	// what if a == b?
	// any works, i get either a+a 0 0 0 -> 2a
	// or a a+anything 0 0 0 -> a+a -> 2a

	// sol:
	// if a > b -> a+b
	// else -> 2a

	if (v[0] > v[1]) cout << v[0] + v[1] << "\n";
	else cout << 2*v[0] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void solve() {
    int a,b,c; cin>>a>>b>>c;

	bool extra = false;
	if (a % 2 != 0) {
		extra = true;
		a--;
	}

	if (b % 2 != 0) {
		extra = true;
		b--;
	}

	if (c % 2 != 0) {
		extra = true;
		c--;
	}

	if (a == b && b == c) extra = false;
	else if ((a > 0) ^ (b > 0) ^ (c > 0)) extra = false;

	int m = max(a, max(b,c));
	int s = a+b+c - m + ((int) extra);

	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}

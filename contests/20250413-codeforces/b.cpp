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

void proc() {
	int n,m,l,r; cin>>n>>m>>l>>r;

	int days = n - m;
	// decrease from right
	int r_dif = min(r, days);	
	r -= r_dif;
	days -= r_dif;

	// increase from left
	l += days;

	cout << l << " " << r << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}

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
	int t; cin >> t;
	int s = 0;
	vec<int> ns_init(t);
	loop(i, 0, t) {
		cin >> ns_init[i];
		s += ns_init[i];
	}
	loop(i, 1, t)  {
		int x;
		loop(i, 0, t) cin >> x;
		ns_init.push_back(x);
		s += x;
	}

	int missing = (2 * t * (2 * t + 1)) / 2 - s;
	cout << missing << " ";
	loop(i, 0, ns_init.size()) cout << ns_init[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}

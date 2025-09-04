#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

int solve() {
    string s; cin >> s;
	vec<int> recipe(3, 0);
	for (char c : s) {
		if (c == 'B') recipe[0]++;
		else if (c == 'S') recipe[1]++;
		else recipe[2]++;
	}

	vec<int> ingr(3);
	loop(i,0,3) cin >> ingr[i];

	vec<int> cost(3);
	loop(i,0,3) cin >> cost[i];

	int rup; cin >> rup;

	// do all that we can normally
	int amt = min({ 
		recipe[0] ? ingr[0] / recipe[0] : INF,
		recipe[1] ? ingr[1] / recipe[1] : INF,
		recipe[2] ? ingr[2] / recipe[2] : INF
	});

	loop(i,0,3) if (!recipe[i]) ingr[i] = 0;
	loop(i,0,3) ingr[i] -= recipe[i] * amt;

	// buy enough ingredients to level all to 0
	while (ingr[0] + ingr[1] + ingr[2] != 0) {
		loop(i,0,3) {
			int needIng = max(0LL, recipe[i] - ingr[i]);
			if (needIng * cost[i] > rup) return amt;
			rup -= needIng * cost[i];
			ingr[i] += needIng;
		}

		loop(i,0,3) {
			ingr[i] -= recipe[i];
			// cout << ingr[i] << " ";
		}
		amt++;
		// cout << "\n";
	}

	// buy as much of all the ingredients needed for a hamburger, n times
	int hambCost = 0;
	loop(i,0,3) hambCost += recipe[i] * cost[i];

	amt += rup / hambCost;

	return amt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}

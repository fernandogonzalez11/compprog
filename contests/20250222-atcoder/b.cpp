#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vec<pair<int, string>> strs(n);
	loop(i, 0, n) {
		string str;
		cin >> str;
		strs[i] = {str.size(), str};
	}

	sort(strs.begin(), strs.end());
	string res = "";
	loop(i, 0, n) res += strs[i].S;

	cout << res << "\n";

	return 0;
}

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

vec<int> convert(string s) {
	vec<int> amounts;
	char curr = 'X';
	loop(i, 0, s.size()) {
		if (s[i] != curr) {
			curr = s[i];
			amounts.push_back(1);
		} else amounts[amounts.size() - 1]++;
	}	

	return amounts;
}

bool proc() {
	string s1, s2; cin >> s1 >> s2;

	if (s1[0] != s2[0]) return false;

	vec<int> conv1 = convert(s1);
	vec<int> conv2 = convert(s2);

	// loop(i, 0, conv1.size()) cout << conv1[i] << " ";
	// cout << "\n";
	// loop(i, 0, conv2.size()) cout << conv2[i] << " ";
	// cout << "\n";

	if (conv1.size() != conv2.size()) return false;

	loop(i, 0, conv1.size()) {
		if (conv1[i] > conv2[i] || conv2[i] > 2 * conv1[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) cout << (proc() ? "YES" : "NO") << "\n";

	return 0;
}

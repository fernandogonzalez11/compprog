#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF 1 << 30 + 1 << 25

using namespace std;

int main() {
	string s; cin >> s;

	// O(n²)
	int cnt = 0;
	loop(i, 0, s.size() - 2) {
		if (s[i] != 'A') continue;
		int dist = 1;
		while (i + 2 * dist < s.size()) {
			if (s[i + dist] == 'B' && s[i + dist * 2] == 'C') cnt++;
			dist++;
		}
	}

	cout << cnt << "\n";

	return 0;
}

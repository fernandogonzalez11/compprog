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

void proc() {
	int n; cin >> n;
	string s; cin >> s;
	
	char state = '0';
	int changes = 0;
	loop(i, 0, n) {
		if (s[i] != state) {
			state = state == '0' ? '1' : '0';
			changes++;
		}
	}

	cout << changes << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) proc();

	return 0;
}

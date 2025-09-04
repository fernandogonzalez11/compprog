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
	
	string s; cin >> s;
	int i = 0;
	while (i < s.size() - 1) {
		if (s[i] == 'W' && s[i+1] == 'A') {
			s[i] = 'A';
			s[i+1] = 'C';
			// check again from 1 place back
			i = max(0, i - 1);
		} else i++;
	}

	cout << s << "\n";

	return 0;
}

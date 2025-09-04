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
	loop(i, 0, s.size())
		if (s[i] == '2') cout << s[i];
	cout << "\n";

	return 0;
}

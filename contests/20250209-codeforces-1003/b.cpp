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

void process(string s) {
	int len = s.size();
	for (int i = len - 2; i >= 0; i--) {
		if (s[i] == s[i + 1]) {
			if (i <= len - 3) s[i] = s[i + 2];
			else if (i >= 1) s[i] = s[i - 1];
			else s[i] = '$';

			for (int j = i + 1; j < len - 1; j++)
				s[j] = s[j + 1];
			s[len - 1] = '\0';
			len--;
			
			// retry
			i++;
		}
	}

	cout << len << "\n";
}

int main() {
	int t; cin >> t;

	while (t--) {
		string s;
		cin >> s;
		process(s);
	}

	return 0;
}

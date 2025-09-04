#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void solve() {
    
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    string s; cin >> s;
	map<char, int> c;

	loop(i, 0, s.size()) {
		c[s[i]]++;
	}

	char odd_one = '\0';
	for (auto p : c) {
		if (p.second % 2 == 1) {
			if (odd_one) {
				cout << "NO SOLUTION" << "\n";
				return 0;
			} else odd_one = p.first;
		}
	}

	int i = 0;
	for (auto p : c) {
		if (p.first != odd_one) {
			int next = i + c[p.first] / 2;
			while (i < next) {
				s[i] = p.first;
				i++;
			}
		}
	}

	if (odd_one) {
		int next = i + c[odd_one];
		while (i < next) {
			s[i] = odd_one;
			i++;
		}
	}

	int j = i - 1;
	if (odd_one) j -= c[odd_one];

	for (; j >= 0; j--) {
		s[i] = s[j];
		i++;
	}

	cout << s << "\n";

	return 0;
}

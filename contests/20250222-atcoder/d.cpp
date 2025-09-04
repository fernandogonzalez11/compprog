#include <bits/stdc++.h>
#include <queue>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

bool is(string s) {
	stack<char> q;
	loop(i, 0, s.size()) {
		char c = s[i];
		switch (c) {
			case '(':
				q.push(')');
				break;
			case '[':
				q.push(']');
				break;
			case '<':
				q.push('>');
				break;

			case ')':
			case ']':
			case '>':
				if (!q.size())  return false;
				char t = q.top();
				if (c != t) return false;
				q.pop();
		}
	}
	
	return !q.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	
	cout << (is(s) ? "Yes" : "No") << "\n";

	return 0;
}

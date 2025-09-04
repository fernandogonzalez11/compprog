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

bool primo(int n) {
	int i = 2;
	while (i * i <= n)
		if (n % i++ == 0) return false;
	 
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	cout << (primo(n) ? "SI" : "NO") << "\n";

	return 0;
}

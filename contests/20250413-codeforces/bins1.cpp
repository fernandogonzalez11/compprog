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

int bins1(vec<int> &arr, int x) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
        int m =  (r - l) / 2 + l;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }

    return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    vec<int> v = {3,5,8,13,18,19,23,29,32};
    cout << bins1(v, 13) << "\n";

	return 0;
}

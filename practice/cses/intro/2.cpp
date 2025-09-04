#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n; cin >> n;
    long long s = 0;
    int x;

    for (int i = 1; i <= n; i++) {
        s ^= i;

        if (i < n) {
            cin >> x;
            s ^= x;
        }
        
    }

    cout << s << "\n";
}

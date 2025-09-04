#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int CNT = 100;

int n;
std::vector<int> x;
vector<int> v;

bool f(double t) {
    double l = (double) x[0] - t * v[0];
    double r = (double) x[0] + t * v[0];
    
    for (int i = 1; i < n; i++) {
        l = max(l, x[i] - t * v[i]);
        r = min(r, x[i] + t * v[i]);
    }

    // cout << "lr " << l << " " << r << "\n";
    
    return l <= r;
}

int main() {
    cout << setprecision(12);

	cin >> n;

    x.resize(n);
    v.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }
    
    // binary search
    // FFFFFTTTT
    // find first T
    double l = 0, r = 1;
    
    while (!f(r)) r *= 2;

    // cout << r << "\n";
    
    for (int k = 0; k < CNT; k++) {
        double t = (r-l)/2+l;
        if (f(t)) r = t;
        else l = t;
    }
    
    cout << r << "\n";
}

#include <bits/stdc++.h>
#include <iomanip>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

void solve() {
    double W, H;
	cin >> W >> H;

	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double w, h;
	cin >> w >> h;

	vec<double> res(4, -1);
	
	// we'll place the second rectangle in different corners
	// start with (0,0)
	// move right, up
	double despx = max(0.0, w - x1),
		despy = max(0.0, h - y1);

	if (x2 + despx <= W)
		res[0] = despx;

	if (y2 + despy <= H)
		res[0] = res[0] == -1 ? despy : min(res[0], despy);

	// now (W-w,0)
	// move left, up 
	despx = max(0.0, x2 - (W-w));
	despy = max(0.0, h - y1);

	if (x1 - despx >= 0)
		res[1] = despx;

	if (y2 + despy <= H)
		res[1] = res[1] == -1 ? despy : min(res[1], despy);

	// now (0, H-h)
	// move right, down
	despx = max(0.0, w - x1);
	despy = max(0.0, y2 - (H-h));

	if (x2 + despx <= W)
		res[2] = despx;

	if (y1 - despy >= 0)
		res[2] = res[2] == -1 ? despy : min(res[2], despy);

	// now (W-w, H-h)
	// move left, down
	despx = max(0.0, x2 - (W-w));
	despy = max(0.0, y2 - (H-h));	
	
	if (x1 - despx >= 0)
		res[3] = despx;

	if (y1 - despy >= 0)
		res[3] = res[3] == -1 ? despy : min(res[3], despy);

	double final = -1;
	loop(i,0,4) {
		if (res[i] != -1) {
			final = final == -1 ? res[i] : min(final, res[i]);
		}
	}

	// loop(i,0,4) cout << res[i] << " "; cout << "\n";
	
	cout << setprecision(12) << final << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

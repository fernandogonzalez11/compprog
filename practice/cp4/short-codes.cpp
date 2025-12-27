#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void ex2() {
    int n;
    cin >> n;
    cout << setprecision(n+1) << M_PI << "\n";
}

int calcNumDays(int y, int m, int d, int *mPref) {
    return (y-1) * 365 + (y-1)/4  + (m==1 ? 0 : mPref[m-2]) + (y%4 == 0 && m>2) + d;
}

void ex3() {
    string days[] = {"monday","tuesday","wednesday","thursday","friday", "saturday", "sunday"};
    int y,m,d, yRef=2025, mRef=11, dRef=17; // today is monday
    cin >> y >> m >> d;
    int mPref[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int i = 1; i < 12; i++) mPref[i] += mPref[i-1];
    int dayC = calcNumDays(y, m, d, mPref);
    int dayRef = calcNumDays(yRef, mRef, dRef, mPref);
    int diff = dayRef-dayC;
    cout << diff << " " << days[(-diff%7+7)%7];
}

void ex4() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    auto last = unique(v.begin(),v.end());
    for (auto it = v.begin(); it<last; it++) cout << *it << " ";
}

void ex5() {
    int n; cin >> n;
    vector<array<int,3>> v(n);
    for (int i = 0; i < n; i++) {
        int y,m,d; cin >> y >> m >> d;
        v[i] = {y,m,d};
    }
    sort(v.begin(),v.end(),[&](array<int,3> a, array<int,3> &b) {
        return a[1]<b[1] || (a[1]==b[1] && (a[0]<b[0] || (a[0]==b[0] && a[2]<b[2])));
    });
    for (auto p : v) printf("%d %d %d\n", p[0],p[1],p[2]);
}

void ex6() {
    int n,x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int l=0, r=n-1;
    while (r-l>1) {
        int m = (r-l)/2+l;
        v[m]>=x ? r = m : l = m;
    }
    cout << (v[l]==x|v[r]==x) << "\n";
}

void ex7() {
    // i forgor lol
}

void ex8() {
    for (int set = 0; set < (1<<20); set++) {
        for (int i = 0; i < 20; i++)
            if (set&(1<<i)) cout << i+1 << " ";
        cout << "\n";
    }
}

void ex9() {
    int x,y;
    string s;
    cin >> s >> x >> y;
    int cnt = 0;
    for (char c : s) {
        int dig;
        if (c>='0'&&c<='9') dig = c-'0';
        else dig = c-'A' + 10;
        cnt = cnt*x + dig;
    }

    string s2;
    while (cnt > 0) {
        int dig = cnt%y;
        (dig < 10) ? (s2 += '0'+dig) : (s2 += 'A'+dig-10);
        cnt /= y;
    }
    reverse(s2.begin(),s2.end());
    cout << s2 << "\n";
}

void ex10() {
    string s;
    getline(cin, s);
    int i = 0;
    while (i < s.length()-2) {
        int j=i;
        while (j<s.length() && s[j]!=' ') j++;
        if (j-i==3 && s[i]>='a'&&s[i]<='z' && s[i+1]>='0'&&s[i+1]<='9' && s[i+2]>='0'&&s[i+2]<='9')
            s[i]=s[i+1]=s[i+2] = '*';

        i = ++j;
    }
    cout << s << "\n";
}

int main() {
    // test code here
    ex10();
}
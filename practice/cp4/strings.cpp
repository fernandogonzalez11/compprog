#include <bits/stdc++.h>
using namespace std;

void ex1() {
    string s, t = "";

    bool h = false;
    while (getline(cin, s), s.substr(0,7) !=  ".......") {
        if (h) t += " ";
        else h = true;
        t += s;
    }
    cout << t << "\n";
};

int main() {
    ex1();
}
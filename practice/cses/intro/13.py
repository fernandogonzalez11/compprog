"""
vector<string> gray(int n) {
    if (n == 1)
        return {"0", "1"};
    
    vector<string> past = gray(n - 1);
    
    vector<string> greys;
    
    int pn = past.size();
    for (int i = 0; i < pn; i++)
        greys.push_back("0" + past[i]);
        
    for (int i = pn - 1; i >= 0; i--)
        greys.push_back("1" + past[i]);
        
    return greys;
}

int main() {
	int n; cin >> n;
	
	vector<string> res = gray(n);
	for (string s : res) cout << s << "\n";
}
"""

from typing import List

def gray(n: int) -> List[str]:
    if n == 1:
        return ["0", "1"]
    
    past_grays = gray(n - 1)

    grays = []

    pgs = len(past_grays)
    for i in range(pgs):
        grays.append("0" + past_grays[i])

    for i in range(pgs - 1, -1, -1):
        grays.append("1" + past_grays[i])

    return grays
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> c;

    for(int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if(c.find(id) == c.end()) {
            c[id] = 1;
        } else {
            c[id]++;
        }
    }

    for(auto it = c.begin(); it != c.end(); it++) {
        if(it->second % k != 0) {
            cout << it->first << endl;
            return 0;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    cin >> s;

    int len = s.size();

    while(s.size() >= 10) {
        cout << s.substr(0, 10) << endl;
        s = s.substr(10);
    }

    cout << s << endl;
    
    return 0;
}
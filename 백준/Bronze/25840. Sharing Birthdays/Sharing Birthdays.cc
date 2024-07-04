#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    set<string> s;
    for(int i = 0;i<n;i++){
        string st;
        cin >> st;
        s.insert(st);
    }

    cout << s.size();
    
    return 0;
}
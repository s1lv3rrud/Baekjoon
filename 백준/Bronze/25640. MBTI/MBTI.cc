#include <bits/stdc++.h>
using namespace std;

int main() {
	string jinho;
	cin >> jinho;
	int n, ans = 0;
	cin >> n;
	while(n!=0){
		string s;
		cin >> s;
		if(jinho == s) ans++;
		n--;
	}
	
	cout << ans;

	return 0;
}
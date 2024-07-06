#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, ans = 0;
	cin >> n;
	n = 1000 - n;
	int ar[6] = {500, 100, 50, 10, 5, 1};
	for(int a : ar){
		ans += n / a;
		n %= a;
	}

	cout << ans;
	
	return 0;
}
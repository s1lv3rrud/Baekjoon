#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, cur = 0;
	cin >> n >> k;

	bool flag = false;
	for(int i = 1;i<=n;i++){
		if(n % i == 0) cur++;
		if(cur == k){
			cout << i;
			flag = true;
			break;
		}
	}

	if(!flag) cout << 0;
	
	return 0;
}
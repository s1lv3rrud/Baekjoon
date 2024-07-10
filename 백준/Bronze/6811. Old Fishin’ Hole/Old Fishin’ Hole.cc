#include <bits/stdc++.h>
using namespace std;

int main() {
	int trout, pike, pickerel, total, ans = 0;
	cin >> trout >> pike >> pickerel >> total;

	for(int i = 0;i<=100;i++){
		for(int j = 0;j<=100;j++){
			for(int k = 0;k<=100;k++){
				if((i || j || k) && i * trout + j * pike + k * pickerel <= total){
					cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel" << endl;
					ans++;
				}
			}
		}
	}

	cout << "Number of ways to catch fish: " << ans;

	return 0;
}
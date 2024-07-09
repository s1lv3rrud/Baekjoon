#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, caseNum = 1;
	cin >> t;

	while(t!=0){
		bool alice = false;
		int n;
		cin >> n;
		vector<long long int> v(n);
		for(int i = 0;i<n;i++){
			cin >> v[i];
		}

		while(n != 2){
			for(int i = 0;i<n/2;i++){
				v[i] += v[n-i-1];
			}
			if(n%2==1){
				v[n/2] *= 2;
				n = n / 2 + 1;
			}else{
				n = n / 2;
			}
		}

		if(v[0] > v[1]) alice = true;

		cout << "Case #" << caseNum << ": ";
		if(alice) cout << "Alice" << endl;
		else cout << "Bob" << endl;
		caseNum++;
		t--;
	}

	
	return 0;
}
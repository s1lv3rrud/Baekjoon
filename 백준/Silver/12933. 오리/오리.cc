#include <bits/stdc++.h>
using namespace std;

string s;
bool ar[2500];
bool ifDone(){
	for(int i = 0;i<s.size();i++){
		if(!ar[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	string quack = "quack";
	int cnt = 0, cur = 0, rep = 0;
	while(!ifDone()){
		if(rep >= s.size()/5){
			cout << -1;
			return 0;
		}
		bool flag = false;
		for (int i = 0; i < s.size(); i++) {
			if(!ar[i] && s[i]==quack[cur]){
				ar[i] = true;
				if(cur==4){
					cur = 0;
					flag = true;
				}
				else cur++;
			}
		}
		if(cur != 0){
			cout << -1;
			return 0;
		}
		if(flag) cnt++;
		rep++;
	}

	cout << cnt;

	return 0;
}
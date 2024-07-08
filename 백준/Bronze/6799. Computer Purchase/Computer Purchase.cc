#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string>& i, pair<int, string>& j){
	if(j.first == i.first) return j.second > i.second;
	return j.first < i.first;
}

int main() {
	int n;
	cin >> n;

	if(n==0) return 0;

	vector<pair<int, string>> v;

	while(n != 0){
		string name;
		cin >> name;
		int r, s, d, pref;
		cin >> r >> s >> d;
		pref = 2 * r + 3 * s + d;
		v.push_back({pref, name});
		n--;
	}

	sort(v.begin(), v.end(), compare);

	cout << v[0].second << endl;
	cout << v[1].second;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ start, end });
	}

	sort(v.begin(), v.end(), cmp);

	int calender[366];
	memset(calender, 0, sizeof(calender));
	for (auto i : v) {
		for (int j = i.first; j <= i.second; j++) {
			calender[j]++;
		}
	}

	int width = 0, height = 0, ans = 0;
	for (int i = 1; i <= 365; i++) {
		if (calender[i] > 0) {
			height = max(height, calender[i]);
			width++;
		}
		else {
			ans += width * height;
			width = 0;
			height = 0;
		}
		if (i == 365) {
			ans += width * height;
			width = 0;
			height = 0;
		}
	}
	
	cout << ans;

    return 0;
}
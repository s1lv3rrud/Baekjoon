#include <bits/stdc++.h>

using namespace std;

int n, maxLen = 0;
vector<int> v, ans;

int binarySearch(int a) {
    int start = 0, end = ans.size() - 1, mid;

    while (start < end) {
		mid = (start + end) / 2;
		if (ans[mid] < a) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
    }
    return end;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a, idx;
    cin >> a;
	v.push_back(a);
	ans.push_back(v.front());
    for (int i = 1; i < n; i++) {
		v.push_back(a);
        cin >> a;
        if (a > ans.back()) {
			ans.push_back(a);
        }
        else {
            idx = binarySearch(a);
            ans[idx] = a;
        }
    }

    cout << ans.size();

    return 0;
}
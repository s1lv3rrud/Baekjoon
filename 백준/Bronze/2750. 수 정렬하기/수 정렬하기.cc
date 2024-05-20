#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> v;
    int n;
    cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

    return 0;
}
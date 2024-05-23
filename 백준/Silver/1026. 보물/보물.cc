#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> v;
    int n;
	int A[50], B[50];
    cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];

	sort(A, A + n);
	sort(B, B + n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += A[i] * B[n - i - 1];
	}
	cout << ans;

    return 0;
}
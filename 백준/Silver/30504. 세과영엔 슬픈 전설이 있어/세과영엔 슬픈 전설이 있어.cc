#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    vector<pair<int, int>> A_with_index(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A_with_index[i] = {A[i], i};
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A_with_index.begin(), A_with_index.end());
    sort(B.begin(), B.end());

    vector<int> result(n);
    int j = 0;
    bool possible = true;

    for (int i = 0; i < n; i++) {
        while (j < n && B[j] < A_with_index[i].first) {
            j++;
        }
        if (j == n) {
            possible = false;
            break;
        }
        result[A_with_index[i].second] = B[j];
        j++;
    }

    if (possible) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
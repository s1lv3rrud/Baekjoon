#include <bits/stdc++.h>

using namespace std;

int n, tmp;
stack<int> st;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;

        if (st.empty()) {
            st.push(tmp);
        }
        else {
            while (!st.empty() && st.top() <= tmp) {
                st.pop();
            }
            sum += st.size();
            st.push(tmp);
        }
    }

    cout << sum;

    return 0;
}

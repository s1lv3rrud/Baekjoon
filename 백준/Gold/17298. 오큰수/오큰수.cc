#include <bits/stdc++.h>

using namespace std;

int n, tmp;
int listA[1000000];
stack<pair<int, int>> st;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(listA, -1, sizeof(int) * 1000000);

    cin >> n;

    int a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;

        if (st.empty()) {
            st.push(make_pair(a, i));
        }
        else {
            while (!st.empty() && st.top().first < a) {
                listA[st.top().second] = a;
                st.pop();
            }
            st.push(make_pair(a, i));
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << listA[i] << " ";
    }

    return 0;
}

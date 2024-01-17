#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, pick, result = 0;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> pick;
        int loc = find(dq.begin(), dq.end(), pick) - dq.begin();
        while (dq.front() != pick) {
            if (loc > dq.size() - loc) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            result++;
        }
        dq.pop_front();
    }
    cout << result;

    return 0;
}
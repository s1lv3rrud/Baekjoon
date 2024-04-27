#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int ar[1000000];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int cur = 1, tmp;
    for (int i = n - 1; i >= 0; i--) {
        switch (ar[i]) {
        case 1:
            dq.push_front(cur++);
            break;
        case 2:
            tmp = dq.front();
            dq.pop_front();
            dq.push_front(cur++);
            dq.push_front(tmp);
            break;
        case 3:
            dq.push_back(cur++);
            break;
        }
    }

    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}
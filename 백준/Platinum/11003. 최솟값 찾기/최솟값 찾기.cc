#include <bits/stdc++.h>

using namespace std;

int n, l, d;
deque<pair<int, int>> dq;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> d;
        if (dq.empty()) {
            dq.push_back(make_pair(d, i));
        }
        else {
            while (!dq.empty() && dq.front().second <= i - l) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back().first >= d) {
                dq.pop_back();
            }
            if (dq.empty() || dq.back().first < d) {
                dq.push_back(make_pair(d, i));
            }
        }
        cout << dq.front().first << "\n";
    }

    return 0;
}

//12 3
//1 5 2 3 6 2 3 7 3 5 2 6
#include <bits/stdc++.h>

using namespace std;

int n, tmp;
stack<pair<int, int>> st;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a = 0;
    long long int sum = 0;

    cin >> a;
    st.push(make_pair(a, 1));

    for (int i = 1; i < n; i++) {
        cin >> a;

        while (!st.empty() && st.top().first < a) {
            sum += st.top().second;
            st.pop();
        }
        if (!st.empty() && st.top().first == a) {
            sum += st.size() == 1 ? st.top().second : st.top().second + 1;
            st.top().second += 1;
        }
        else if(st.empty()){
            st.push(make_pair(a, 1));
        }
        else {
            sum += 1;
            st.push(make_pair(a, 1));
        } 
    }

    cout << sum;

    return 0;
}

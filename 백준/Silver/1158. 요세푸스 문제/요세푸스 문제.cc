#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    list<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    auto it = people.begin();
    for (int i = 1; i < k; i++) {
        it++;
    }

    cout << "<";

    while (!people.empty()) {
        if (it == people.end()) it = people.begin();
        cout << *it;
        if (people.size() == 1) break;
        cout << ", ";
        it = people.erase(it);
        for (int i = 1; i < k; i++) {
            if (it == people.end()) it = people.begin();
            it++;
        }
    }

    cout << ">";

    return 0;
}
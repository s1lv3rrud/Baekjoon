#include <bits/stdc++.h>

using namespace std;

long long dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> dot(4);
        for (int j = 0; j < 4; j++) {
            cin >> dot[j].first >> dot[j].second;
        }
        
        vector<long long> distances;
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                distances.push_back(dist(dot[j], dot[k]));
            }
        }
        
        sort(distances.begin(), distances.end());
        
        if (distances[0] > 0 && 
            distances[0] == distances[1] && 
            distances[1] == distances[2] && 
            distances[2] == distances[3] &&  // 변의 길이 4개가 같아야 함
            distances[4] == distances[5]) {  // 대각선의 길이 2개가 같아야 함
            cout << 1 << "\n";  // 정사각형
        } else {
            cout << 0 << "\n";  // 정사각형 아님
        }
    }

    return 0;
}
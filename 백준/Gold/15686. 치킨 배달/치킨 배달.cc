#include <bits/stdc++.h>

using namespace std;

int n, m, minDis = 999999;
int city[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool combi[13];

int solve() {
    int dis = 0;
    for (int i = 0; i < house.size(); i++) {
        int chickenDis = 999999;
        for (int j = 0; j < chicken.size(); j++) {
            if (combi[j]) {
                chickenDis = min(chickenDis,
                    abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
            }
        }
        dis += chickenDis;
    }

    return dis;
}
void combination(int curIndex, int curNum) {
    if (curNum == m) {
        minDis = min(minDis, solve());
        return;
    }

    for (int i = curIndex; i < chicken.size(); i++) {
        combi[i] = true;
        combination(i + 1, curNum + 1);
        combi[i] = false;
    }

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                house.push_back(make_pair(i, j));

            }
            else if (city[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    combination(0, 0);

    cout << minDis;

    return 0;
}
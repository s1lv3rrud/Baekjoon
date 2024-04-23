#include <bits/stdc++.h>

using namespace std;

int ar[30][30];

pair<int, int> solve(int n, int walk) {
    if (n == 2) {
        switch (walk) {
        case 1:
            return { 1, 1 };
        case 2:
            return { 1, 2 };
        case 3:
            return { 2, 2 };
        case 4:
            return { 2, 1 };
        }
    }
    
    int half = n / 2;
    int sector = half * half;
    pair<int, int> tmp;

    // 좌측 하단
    if (walk <= sector) {
        tmp = solve(half, walk);
        return { tmp.second, tmp.first };
    }
    // 좌측 상단
    else if (walk <= 2 * sector) {
        tmp = solve(half, walk - sector);
        return { tmp.first, tmp.second + half };
    }
    // 우측 상단
    else if (walk <= 3 * sector) {
        tmp = solve(half, walk - 2 * sector);
        return { tmp.first + half, tmp.second + half };
    }
    // 우측 하단
    else {
        tmp = solve(half, walk - 3 * sector);
        return { 2 * half - tmp.second + 1, half - tmp.first + 1 };
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> result = solve(n, m);
    cout << result.first << " " << result.second;

    return 0;
}
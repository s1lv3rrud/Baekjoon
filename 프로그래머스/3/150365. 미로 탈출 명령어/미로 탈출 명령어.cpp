#include <bits/stdc++.h>

using namespace std;

string answer = "impossible";
string ans = "";
int n, m, x, y, r, c, k;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };
char dir[4] = { 'd','l','r','u' }; // 사전순
bool flag = false;

void dfs(int curx, int cury, int cnt) {
    if (!flag) {
        int dist = abs(curx - r) + abs(cury - c);
        if (k - cnt - dist < 0) return;
        if ((k - cnt - dist) % 2 == 1) return;

        if (cnt == k) {
            if (curx == r && cury == c) {
                flag = true;
                answer = ans;
            }
            return;
        }
        for (int k = 0; k < 4; k++) {
            int nx = curx + dx[k];
            int ny = cury + dy[k];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                ans += dir[k];
                dfs(nx, ny, cnt + 1);
                ans.pop_back();
            }
        }
    }
}

string solution(int _n, int _m, int _x, int _y, int _r, int _c, int _k) {
	n = _n, m = _m, x = _x, y = _y, r = _r, c = _c, k = _k;

    dfs(x, y, 0);

    return answer;
}
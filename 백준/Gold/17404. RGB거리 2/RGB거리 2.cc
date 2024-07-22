#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MAX;
int rgb[1000][3];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

	for(int first = 0;first<3;first++){
		int cost[1000][3];
		for(int i = 0;i<3;i++){
			if(i==first) cost[0][i] = rgb[0][i];
			else cost[0][i] = 1000*1000+1;
		}

		for (int i = 1; i < n; i++) {
        	cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + rgb[i][0];
        	cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + rgb[i][1];
        	cost[i][2] = min(cost[i - 1][1], cost[i - 1][0]) + rgb[i][2];
    	}

		for(int i = 0;i<3;i++){
			if(i==first) continue;
			ans = min(ans,cost[n-1][i]);
		}
	}

    cout << ans;

    return 0;
}
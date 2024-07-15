#include <bits/stdc++.h>
using namespace std;

int n;
bool ar[33][33];
long long int dp[33][33][3]; // 오른쪽 아래 오른쪽아래

void solve(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(!ar[i][j+1]) dp[i][j+1][0] += dp[i][j][0] + dp[i][j][2];
            if(!ar[i+1][j]) dp[i+1][j][1] += dp[i][j][1] + dp[i][j][2];
            if(!ar[i+1][j+1] && !ar[i][j+1] && !ar[i+1][j])
                dp[i+1][j+1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        }
    }
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    
    dp[1][2][0] = 1;

    solve();
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    
    return 0;
}
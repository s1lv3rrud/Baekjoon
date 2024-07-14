#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
bool ar[17][17];
queue<tuple<int, int, int, int>> q; // x1, y1, x2, y2

bool isIn(int x, int y){
    return x <= n && y <= n;
}

void bfs(){
    while(!q.empty()){
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = q.front();
        q.pop();

        if(x1==x2){ // 가로
            // 오른쪽 이동
            if(isIn(x2, y2+1) && !ar[x2][y2+1]){
                if(x2==n &&y2+1==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2, y2+1});
                }
            }
            // 오른쪽 이동 및 회전 // 대각선
            if( isIn(x2+1, y2+1) && !ar[x2+1][y2+1] && !ar[x2][y2+1] && !ar[x2+1][y2]){
                if(x2+1==n && y2+1==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2+1, y2+1});
                }
            }
        }
        else if(y1==y2){ // 세로
            // 아래 이동
            if(isIn(x2+1, y2) && !ar[x2+1][y2] ){
                if(x2+1==n && y2==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2+1, y2});
                }
            }
            // 아래 이동 및 회전 // 대각선
            if(isIn(x2+1, y2+1) && !ar[x2+1][y2+1] && !ar[x2][y2+1] && !ar[x2+1][y2]){
                if(x2+1==n && y2+1==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2+1, y2+1});
                }
            }
        }
        else{ // 대각선
            // 오른쪽 이동 및 회전
            if(isIn(x2, y2+1) && !ar[x2][y2+1]){
                if(x2==n &&y2+1==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2, y2+1});
                }
            }
            // 아래 이동 및 회전
            if(isIn(x2+1, y2) && !ar[x2+1][y2]){
                if(x2+1==n && y2==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2+1, y2});
                }
            }
            // 오른쪽 아래 이동 // 대각선
            if(isIn(x2+1, y2+1) && !ar[x2+1][y2+1] && !ar[x2][y2+1] && !ar[x2+1][y2]){
                if(x2+1==n && y2+1==n){
                    ans++;
                }else{
                    q.push({x2, y2, x2+1, y2+1});
                }
            }
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

    q.push({1, 1, 1, 2});
    
    bfs();
    
    cout << ans;
    
    return 0;
}
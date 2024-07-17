#include <bits/stdc++.h>

using namespace std;

vector<int> answer(2, 0);
vector<int> discount(7);
int percent[4] = {10, 20, 30, 40};

void dfs(int cur, vector<vector<int>> users, vector<int> emoticons){
    if(cur == emoticons.size()){
        int totalPlus = 0, totalMoney = 0;
        for(auto u : users){
            int money = 0;
            for(int i = 0;i<emoticons.size();i++){
                if(u[0] <= discount[i]){
                    money += emoticons[i] * (100 - discount[i]) / 100;
                }
            }
            if(money >= u[1]){
                totalPlus += 1;
            }else{
                totalMoney += money;
            }
        }
        if(totalPlus > answer[0]){
            answer[0] = totalPlus;
            answer[1] = totalMoney;
        }else if(totalPlus == answer[0]){
            answer[1] = max(answer[1], totalMoney);
        }
        return;
    }
    for(auto p : percent){
        discount[cur] = p;
        dfs(cur + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    dfs(0, users, emoticons);  
    
    return answer;
}
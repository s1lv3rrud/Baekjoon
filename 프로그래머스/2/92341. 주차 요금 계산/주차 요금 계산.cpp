#include <bits/stdc++.h>

using namespace std;

int calTime(string start, string end){
    int startHour = stoi(start.substr(0, 2));
    int startMin = stoi(start.substr(3, 2));
    int endHour = stoi(end.substr(0, 2));
    int endMin = stoi(end.substr(3, 2));
    return (endHour - startHour) * 60 + (endMin - startMin);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, vector<string>> m; // 차량번호, 시간 로그
    
    for(auto record : records){
        string car = record.substr(6, 4);
        if(m.find(car) == m.end()){
            m[car] = vector<string>();
        }
        m[car].push_back(record.substr(0, 5));
    }
    for(auto car : m){
        int totalTime = 0, totalFee = 0;
        if(car.second.size() % 2 == 1){
            car.second.push_back("23:59");
        }
        for(int i = 0; i < car.second.size(); i += 2){
            totalTime += calTime(car.second[i], car.second[i + 1]);
        }
        if(totalTime <= fees[0]){
            totalFee = fees[1];
        }else{
            if((totalTime-fees[0]) % fees[2] != 0){
                totalFee = fees[1] + ((totalTime-fees[0]) / fees[2] + 1) * fees[3];
            }
            else{
                totalFee = fees[1] + ((totalTime-fees[0]) / fees[2]) * fees[3];
            }
        }
        answer.push_back(totalFee);
    }    
    
    return answer;
}
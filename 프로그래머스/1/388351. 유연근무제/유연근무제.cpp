#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int p = schedules.size();
    
    for(int i = 0; i < p; i++){
        int s = schedules[i];
        int st = s / 100 * 60 + s % 100;
        vector<int> t = timelogs[i];
        int tarr[7];
        for(int j = 0; j < 7; j++){
            tarr[j] = t[j] / 100 * 60 + t[j] % 100;
            cout << "j : " << j << " : " << t[j] / 100 << " : " << t[j] % 100 << "\n";
        }
        int temp = 1;
        int starttemp = startday;
        for(int j = 0; j < 7; j++){
            if(starttemp % 7 == 6 || starttemp % 7 == 0){//startday 가 6 혹은 7
                cout << "starttemp : " << starttemp << "\n";
                starttemp = starttemp % 7 + 1;
                
                continue;
            }
            if(tarr[j] <= st + 10){
                starttemp++;
                continue;
            }
            else if(tarr[j] > st + 10) temp = 0;
            
            if(temp == 0) break;
        }
        if(temp == 1) answer++;
    }
    return answer;
}
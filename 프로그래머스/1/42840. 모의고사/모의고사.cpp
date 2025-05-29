#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    int std2_arr[4] = {1, 3, 4, 5};
    int std3_arr[5] = {3, 1, 2, 4, 5};
    int std1 = 1;
    int cnt1 = 0;
    int std2 = 2;
    int cnt2 = 0;
    int std3 = 3;
    int cnt3 = 0;
    for(int i = 0; i < answers.size(); i++){
        
        std1 = i % 5 + 1;
        if(i % 2 == 0) std2 = 2;
        else std2 = std2_arr[(i % 8) / 2];
        std3 = std3_arr[(i % 10) / 2];
            
        if(std1 == answers[i]) cnt1++;
        if(std2 == answers[i]) cnt2++;
        if(std3 == answers[i]) cnt3++;
        
    }
    
    int max_score = max(max(cnt1, cnt2), cnt3);
    if(cnt1 == max_score) result.push_back(1);
    if(cnt2 == max_score) result.push_back(2);
    if(cnt3 == max_score) result.push_back(3);
    
    return result;
}
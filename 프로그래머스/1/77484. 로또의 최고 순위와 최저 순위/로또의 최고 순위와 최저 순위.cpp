#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int right = 0;
    int joker = 0;
    for(int i = 0; i < lottos.size(); i++)if(!lottos[i]) joker++;
    
    for(int i = 0; i < lottos.size(); i++){
        if(!lottos[i]) continue;
        for(int j = 0; j < win_nums.size(); j++){
            if(lottos[i] == win_nums[j]){
                right++;
                break;
            }
        }
    }
    
    
    if(right + joker < 2) answer.push_back(6);
    else answer.push_back(7 - right - joker);
    
    if(right < 2) answer.push_back(6);
    else answer.push_back(7 - right);
    // answer.push_back(right);
    // answer.push_back(right + joker);
    
    return answer;
}
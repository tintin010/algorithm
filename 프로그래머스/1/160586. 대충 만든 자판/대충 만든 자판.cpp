#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    int alp[26];
    for(int i = 0; i < 26; i ++) alp[i] = 101;
    
    for(int i = 0; i < keymap.size(); i++){
        int len = keymap[i].size();
        for(int j = 0; j < len; j++){
            int a = keymap[i][j] - 'A';
            if(alp[a] > j + 1) alp[a] = j + 1;
        }
    }
    
    for(int i = 0; i < targets.size(); i++){
        int len = targets[i].size();
        int temp = 0;
        for(int j = 0; j < len; j++){
            int t = targets[i][j] - 'A';
            if(alp[t] > 100) {
                temp = -1;
                break;
            }else{
                temp += alp[t];
            }
        }
        answer.push_back(temp);
    }
    
    return answer;
}
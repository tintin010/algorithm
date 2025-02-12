#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum = 0;
    
    map<string, int>miss;
    for(int i = 0; i < name.size(); i++){
        miss[name[i]] = yearning[i];
    }
    
    for(int i = 0;i < photo.size(); i++){
        sum = 0;
        for(int j = 0; j < photo[i].size(); j++){
            if(!miss[photo[i][j]]) continue;
            sum += miss[photo[i][j]];
        }
        answer.push_back(sum);
    }
    
    return answer;
}
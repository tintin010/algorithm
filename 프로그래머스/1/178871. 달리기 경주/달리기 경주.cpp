#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    answer = players;
    
    // map<int, string>m1;
    map<string, int>m;
    
    for(int i = 0; i < players.size(); i++){
        // m1[i] = players[i];
        m[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++){
        int rank = m[callings[i]];
        m[answer[rank - 1]] += 1;
        m[callings[i]] -= 1;
        swap(answer[rank], answer[rank - 1]); 
    }
    return answer;
}
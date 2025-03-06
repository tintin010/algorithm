#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int len = participant.size();
    unordered_map <string, int> label;
    
    for(auto p : participant){
        if(label.end() == label.find(p)){
            label.insert(make_pair(p, 1));
        }else label[p]++;
    }
    
    for(auto c : completion) label[c]--;
    
    for(auto p : participant){
        if(label[p] > 0){
            answer = p;
            break;
        }
    }
    
    return answer;
}
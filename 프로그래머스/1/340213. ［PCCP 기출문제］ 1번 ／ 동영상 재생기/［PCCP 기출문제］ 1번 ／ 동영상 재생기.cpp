#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int vl = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int pl = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int osl = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int oel = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
    
    for(auto c : commands){
        if(pl >= osl && pl <= oel) pl = oel;
        if(c.compare("next") == 0){            
            if((vl - pl) < 10) pl = vl;
            else pl += 10;
        }else if(c.compare("prev") == 0){
            if(pl < 10) pl = 0;
            else pl -= 10;
            
        }
        if(pl >= osl && pl <= oel) pl = oel;
    }
    answer = to_string(pl / 60) + ":";
    if(pl % 60 == 0)answer += "00";
    else{
        if(to_string(pl % 60).length() == 1)
        answer = answer + "0" + to_string(pl % 60);
        else answer = answer + to_string(pl % 60);
    }
    
    if(answer.length() < 5)answer = "0" + answer;
    
    
    return answer;
}
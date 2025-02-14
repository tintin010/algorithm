#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    
    int answer = 1000;
    
    string str;
    int count;
    
    if (s.length() == 1) {
        return 1;
    }
    
    for(int i = 1; i <= s.length()/2; i++){
        string temp = "";
        str = s.substr(0, i);
        count = 1;
        for(int j = i; j < s.length(); j += i){
            if(str.compare(s.substr(j, i)) == 0){
                 count++;
            }else{
                if(count > 1){
                    temp += to_string(count) + str;
                    str = s.substr(j, i);
                }else{
                    temp += str;
                    str = s.substr(j, i);
                }
                count = 1;
            }
        }
        if(count > 1) temp += to_string(count);
        temp += str;
        if(answer > temp.length()){
             answer = temp.length();
        }
    }
    
    return answer;
}
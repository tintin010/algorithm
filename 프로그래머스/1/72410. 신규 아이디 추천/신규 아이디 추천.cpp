#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    
    int length = new_id.size();
    string temp = "";
    for(int i =0; i < length; i++){
        //1단계
        if(isupper(new_id[i])) temp += tolower(new_id[i]);
        //2단계
        else if(isalpha(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') temp += new_id[i];
    }
    
    new_id = temp;
    temp = "";
    
    for( auto a : new_id){
        if(a == '.' && temp.back() == '.') continue;
        else temp += a;
    }
    new_id = temp;
    temp = "";
    
    if(new_id.front() == '.') new_id.erase(0, 1);
    if(new_id.back() == '.') new_id.pop_back();
    
    if(new_id.empty()) new_id = "a";
    
    if(new_id.length() >= 16) new_id.erase(new_id.begin()+15, new_id.begin() + new_id.size());    //new_id.end()
    if(new_id.back() == '.') new_id.pop_back();
    
    
    while(new_id.length() < 3) {
        new_id += new_id.back();
    }
    
    
    return new_id;
}
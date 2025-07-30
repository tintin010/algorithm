#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    
    map<string, pair<int, int>> mp;
    int like = 0;
    int other = 0;
    
    for(int i = 0; i < str1.length(); i++) str1[i] = tolower(str1[i]);
    for(int i = 0; i < str2.length(); i++) str2[i] = tolower(str2[i]);
    
    for(int i = 0; i < str1.length() - 1; i++){
        if(isalpha(str1[i]) && isalpha(str1[i + 1])){
            mp[str1.substr(i, 2)].first++;
        }
    }
    
    for(int i = 0; i < str2.length() - 1; i++){
        if(isalpha(str2[i]) && isalpha(str2[i + 1])){
            mp[str2.substr(i, 2)].second++;
        }
    }
    
    for(auto it : mp){
        like += min(it.second.first, it.second.second);
        other += max(it.second.first, it.second.second);
    }
    
    double answer = 0;
    
    if(like == 0 && other == 0) answer = 1.0;
    else answer = (double)like / (double)other;
    
    
    int fin = answer * 65536;
    
    return fin;
}
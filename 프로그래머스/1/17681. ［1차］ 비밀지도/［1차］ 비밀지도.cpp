#include <string>
#include <vector>

using namespace std;

string treasure(int t1, int t2, int maxi){
    
    string temp = "";
    
    while(maxi){
        
        if(t1 / maxi || t2 / maxi) temp += "#";
        else temp += " ";

        if(t1 / maxi) t1 -= maxi;
        if(t2 / maxi) t2 -= maxi;
        
        maxi = maxi / 2;
    }
    
    return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    int maxi = 1;
    for(int i = 0; i < n - 1; i++) maxi *= 2;
    
    for(int i = 0; i < n; i++){
        int t1 = arr1[i];
        int t2 = arr2[i];
        
        answer.push_back(treasure(t1, t2, maxi));
    }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstring>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int len = id_list.size();
    int arr[len][len];
    int ans[len];
    map <string, int>user;
    
    memset(arr, 0, sizeof(arr));
    memset(ans, 0, sizeof(ans));
    
    for(int i = 0;i < len; i++){
        user[id_list[i]] = i;
    }
    
    for(int i = 0; i < report.size(); i++){
        stringstream ss(report[i]);
        string alert;
        string alerted;
        ss >> alert >> alerted;
        
        arr[user[alert]][user[alerted]] += 1;
    }
    
    for(int i = 0; i< len; i++){
        int total = 0;
        for(int j = 0; j < len; j++){
            if(arr[j][i]) total++;
        }
        if(total >= k){
            for(int j = 0; j < len; j++){
                if(arr[j][i]) ans[j] += 1;
            }
        }
    }
    for(auto a : ans) answer.push_back(a);
    return answer;
}
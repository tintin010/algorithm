#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int len = friends.size();
    map<string, int> person;
    vector<int> index(len, 0);
    int gift_arr[len][len];
    
    memset(gift_arr, 0, sizeof(gift_arr));
    
    for(int i = 0; i < len; i++){
        person[friends[i]] = i; 
    }
    
    for(int i = 0; i < gifts.size(); i++){
        stringstream ss(gifts[i]);
        string give;
        string take;
        
        ss >> give >> take;
        
        gift_arr[person[give]][person[take]] += 1;
        
        index[person[give]]++;
        index[person[take]]--;
    }
    
    int nextmonth[len];
    memset(nextmonth, 0, sizeof(nextmonth));
    
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(i == j || gift_arr[i][j] < gift_arr[j][i]) continue;
            if(gift_arr[i][j] > gift_arr[j][i]){
                nextmonth[i]++;
            }else if(index[i] > index[j]){
                nextmonth[i]++;
                // int tempI = 0;
                // int tempJ = 0;
                // for(int k = 0; k < len; k++){
                //     tempI = tempI + gift_arr[i][k] - gift_arr[k][i];
                //     tempJ = tempJ + gift_arr[j][k] - gift_arr[k][j];
                // }
                // if(tempI > tempJ) nextmonth[i]++;
                // else if(tempJ > tempI) nextmonth[j]++;
                // else continue;
            }
        }
    }
    for(int i = 0; i < len; i++){
        if(answer < nextmonth[i]) answer = nextmonth[i];
    }
    // answer /=2;
    
    return answer;
}
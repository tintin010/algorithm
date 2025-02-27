#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    map <string, int> idx;
    idx["code"] = 0;
    idx["date"] = 1;
    idx["maximum"] = 2;
    idx["remain"] = 3;
    
    int std = idx[ext];
    vector<vector<int>> fir_t;
    
    for(int i = 0; i < data.size(); i++){
        if(data[i][std] < val_ext) fir_t.push_back(data[i]); 
    }
    
    int std2 = idx[sort_by];
    
    for(int i = 0; i < fir_t.size(); i++){
        for(int j = i + 1; j < fir_t.size(); j++){
            if(fir_t[i][std2] > fir_t[j][std2]){
                vector<int> temp = fir_t[i];
                fir_t[i] = fir_t[j];
                fir_t[j] = temp;
            }
        }
    }
    
    return fir_t;
}
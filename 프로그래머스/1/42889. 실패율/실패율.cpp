#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<double, int> &a, pair<double, int> &b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failure;
    int noClearStage;
    int noReachStage = 0;
    int cnt[501];
    
    for(int i = 0; i <= N; i++){
        cnt[i] = 0;  
    }
    
    for(int i = 0; i < stages.size(); i++){
        cnt[stages[i]]++;
    }
    
    int total = stages.size();
    
    for(int i = 1; i <= N; i++){
        if(cnt[i] == 0) failure.push_back({0, i});
        else{
            double result = (double)cnt[i] / total;
            failure.push_back({result, i});
        }
        total -= cnt[i];
    }
    sort(failure.begin(), failure.end(), cmp);
    
    for(int i = 0; i < failure.size(); i++){
        answer.push_back(failure[i].second);
    }

    return answer;
}
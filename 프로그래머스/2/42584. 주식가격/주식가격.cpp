#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    
    deque <pair<int, int>> q;
    
    for(int i = 0; i < prices.size(); i++){
        
        while(!q.empty() && q.front().first > prices[i]){
            answer[q.front().second] = i - q.front().second;
            q.pop_front();
        }
        
        q.push_front(make_pair(prices[i], i));
    }
    while (!q.empty()) {
        answer[q.front().second] = n - q.front().second - 1;
        q.pop_front();
    }
    return answer;
}
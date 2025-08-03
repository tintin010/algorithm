#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    map <int, int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m.count(nums[i])) m[nums[i]]++;
        else m[nums[i]] = 1;
    }
    int l = nums.size() / 2;
    int answer;
    if(l < m.size()) answer = l;
    else answer = m.size();
    return answer;
}
#include <string>
#include <vector>
//#include <libstd.h>
#include <math.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int arr[n + 1];
    for(int i = 1; i <= n; i++) arr[i] = 1;
    for(int i = 0; i < lost.size(); i++){
        arr[lost[i]]--;
    }
    for(int i = 0; i < reserve.size(); i++){
        arr[reserve[i]]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(!arr[i]){
            if(i - 1 > 0 && arr[i - 1] > 1){
                arr[i]++;
                arr[i - 1]--;
            }else if(i + 1 <= n && arr[i + 1] > 1){
                arr[i]++;
                arr[i + 1]--;
            }
        }
    }
    for(int i = 1; i <= n; i++) if(arr[i]) answer++;
    return answer;
}
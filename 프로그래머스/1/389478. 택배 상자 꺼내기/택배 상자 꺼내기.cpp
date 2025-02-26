#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
        
    int fin = (n - (n % w)) / w;
    
    int m = num / w;
    if(num % w > 0) m++;
    
    int answer = fin - m + 1;
    cout << "ans : " << answer << "\n";
    if(num % w > 0) m--;
    if((num % w) ==0 && n % w == 0) return answer;
    if(fin % 2){            //홀수
        if(m % 2){
            
            if(num % w <= n % w) answer++;
            
        }else if(!(m % 2)){
            if(num % w + n % w > w) answer++;
        }
    }else if(! (fin % 2)){  // 짝수
        if(m % 2){
            if(num % w + n % w > w) answer++;
        }else if(!(m % 2)){
            if(num % w <= n % w) answer++;
        } 
    }
    return answer;
}
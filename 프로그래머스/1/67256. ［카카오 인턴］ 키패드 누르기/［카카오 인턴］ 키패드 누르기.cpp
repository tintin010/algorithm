#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_y = 3, l_x = 0, r_y = 3, r_x = 2;
    
    for(auto n : numbers){
        // cout << "n : " << n << "\n";
        if(n == 1 || n == 4 || n == 7){
            answer = answer + "L";
            l_x = 0;
            l_y = n / 3;
            cout << l_y << " : " << l_x << " : " << r_y << " : " << r_x << "\n"; 
        }else if(n == 3 || n == 6 ||n == 9){
            answer = answer + "R";
            r_x = 2;
            r_y = n / 3 - 1;
            cout << l_y << " : " << l_x << " : " << r_y << " : " << r_x << "\n"; 
        }else {
            int t_y, t_x;
            if(n > 0){
                t_y = n / 3;
                t_x = 1;
            }else{
                t_y = 3;
                t_x = 1;
            }
            
            if(abs(t_x - l_x) + abs(t_y - l_y) > abs(t_x - r_x) + abs(t_y - r_y)){
                answer = answer + "R";
                r_x = t_x;
                r_y = t_y;
                cout << l_y << " : " << l_x << " : " << r_y << " : " << r_x << "\n"; 
            }else if(abs(t_x - l_x) + abs(t_y - l_y) < abs(t_x - r_x) + abs(t_y - r_y)){
                answer = answer + "L";
                l_x = t_x;
                l_y = t_y;
                cout << l_y << " : " << l_x << " : " << r_y << " : " << r_x << "\n"; 
            }else if(abs(t_x - l_x) + abs(t_y - l_y) == abs(t_x - r_x) + abs(t_y - r_y)){
                if(hand.length() > 4){
                    answer = answer + "R";
                    r_x = t_x;
                    r_y = t_y; 
                    cout << l_y << " : " << l_x << " : " << r_y << " : " << r_x << "\n"; 
                }else{
                    answer = answer + "L";
                    l_x = t_x;
                    l_y = t_y;
                    cout << l_y << " : " << l_x << " : " << r_y << " : " << r_x << "\n"; 
                }
            }
        }
    }
    return answer;
}
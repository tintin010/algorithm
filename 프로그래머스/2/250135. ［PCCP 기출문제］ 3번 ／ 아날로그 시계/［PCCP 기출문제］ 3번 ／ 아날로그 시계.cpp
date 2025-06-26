#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int st = h1 * 3600 + m1 * 60 + s1;
    int end = h2 * 3600 + m2 * 60 + s2;
    int during = end - st;
    
    int track = 12 * 3600;
    int h = h1 % 12 * 3600 + m1 * 60 + s1;;
    int m = (m1 * 60 + s1) * 12;
    int s = s1 * 12 * 60;
    int ms = 1; // 0 이면 초침보다 분침이 앞선다; 1 이면 초침이 분침 앞선다.
    int hs = 1;
    if(s < m) ms = 0;
    if(s < h) hs = 0;
    // cout << ms << hs << '\n';
    if(s == m || s == h){
        answer++;
    }
    for(int i = 1; i <= during ; i++){
        h += 1;
        m += 12;
        s += 720;
        
        if(ms == 0 && s >= m){
            ms = 1;
            answer++;
        }
        if(hs == 0 && s >= h){
            hs = 1;
            answer++;
        }
        if((m == h) && m == track) answer--;
        if(h == track) h = 0;
        if(m == track) m = 0;
        if(s == track){
            s = 0;
            if(s != m) ms = 0;
            if(s != h) hs = 0;
        }
    }
    return answer;
}
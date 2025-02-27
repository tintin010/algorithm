#include <iostream>

using namespace std;

int gcd(long long w, long long h){
    int b = h;
    int s = w;
    if(w > h){
        b = w;
        s = h;
    }
    int mod = b % s;
    
    while(mod > 0){
        b = s;
        s = mod;
        mod = b % s;
    }
    return s;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long W = w;
    long long H = h;
    long long mx = w * h;
    
    int g = gcd(W, H);
    
    answer = W * H - (W + H - g);
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int x[X.length()];
    int y[Y.length()];
    
    int ans[3000001];
    int ansc = 0;
    
    for(int i = 0; i < X.length(); i++) x[i] = X[i] - '0';
    for(int i = 0; i < Y.length(); i++) y[i] = Y[i] - '0';
    
    sort(x, x + X.length());
    sort(y, y + Y.length());
    
    int cx = 0;
    int cy = 0;
    
    // cout << "Y.length() : " << Y.length() << endl;
    
    while(cx < X.length() && cy < Y.length()){
        // cout << cx << " : " << cy << "\n";
        if(x[cx] == y[cy]){
            // cout << "x : " << x[cx] << " y : " << y[cy] << endl;
            ans[ansc] = x[cx];
            ansc++;
            cx++;
            cy++;
            // cout << "cx : " << cx << " cy : " << cy << endl;
        }else if(x[cx] > y[cy]){
            cy++;
        }else if(x[cx] < y[cy]){
            cx++;
        }
    }
    if(ansc == 0) return "-1";
    sort(ans, ans + ansc);
    
    if(ans[ansc - 1] == 0) return "0";
    
    for(int i = ansc - 1; i >= 0; i--){
        answer += to_string(ans[i]);
    }
    
    return answer;
}
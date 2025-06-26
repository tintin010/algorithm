#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    while(true){
        string str;
        stack <char> qcy;
        getline(cin, str);
        if(str == ".") break;
        int l = str.length();
        int flag = 1;
        for(int i = 0; i < l; i++){
            char c = str[i];
            if((c == '(') || (c == '[')) qcy.push(c);
            else if(c == ')'){
                if(!qcy.empty() && qcy.top() == '(') qcy.pop();
                else{
                    flag = 0;
                    break;
                }
            }else if(c == ']'){
                if(!qcy.empty() && qcy.top() == '[') qcy.pop();
                else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0 || !qcy.empty()) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
    return 0;
}
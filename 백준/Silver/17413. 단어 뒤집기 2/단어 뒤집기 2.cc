#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string init;
    getline(cin, init);
    int len = init.length();
    int i = 0;
    while(i < len){
        if(init[i] == '<'){
            cout << init[i];
            i++;
            while(true){
                if(init[i] == '>'){
                    cout << '>';
                    i++;
                    break;
                }else{
                    cout << init[i];
                    i++;
                }
            }
        }else{
            stack <char> word;
            word.push(init[i]);
            i++;
            while(true){
                if(i == len || init[i] == ' ' || init[i] == '<'){
                    int size = word.size();
                    for(int k = 0; k < size; k++){
                        cout << word.top();
                        word.pop();
                    }
                    if(init[i] == ' ') cout << ' ';
                    else if(init[i] == '<') i--;
                    i++;
                    break;
                }else{
                    word.push(init[i]);
                    i++;
                }
            }
        }
    }
    return 0;
}
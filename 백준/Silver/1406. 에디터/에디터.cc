#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    list <char> l(str.begin(), str.end());
    auto cursor = l.end();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char cmd;
        cin >> cmd;
        if(cmd == 'P'){
            char input;
            cin >> input;
            l.insert(cursor, input);
            
        }else if(cmd == 'L'){
            if(cursor != l.begin()){
                cursor--;
            }
        }else if(cmd == 'D'){
            if(cursor != l.end()){
                cursor++;
            }
        }else if(cmd == 'B'){
            if(cursor != l.begin()){
                cursor--;
                cursor = l.erase(cursor);
            }
        }
    }
    for (cursor = l.begin(); cursor != l.end(); cursor++) cout << *cursor;
    return 0;
}
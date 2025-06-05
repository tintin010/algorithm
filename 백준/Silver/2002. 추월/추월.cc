#include <iostream>
#include <queue>
#include <string.h>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    int result = 0;

    queue <string> in;
    map <string, int> idx;
    queue <string> out;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        idx[temp] = 1;
        in.push(temp);
    }

    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        out.push(t);
    }

    for(int i = 0; i < n; i++){
        string a = out.front();
        // cout << "in.front().compare(a) : " << !in.front().compare(a) << '\n';
        // cout << "in.front() : " << in.front() << "::  a : " << a << '\n';

        if(!in.front().compare(a)){
            out.pop();
            in.pop();
            idx[a] = 0;
        }else{
            if(idx[in.front()] == 0){
                // cout << "이미 봄 : " << a << '\n';
                i -= 1;
                in.pop();
                continue;
            }else{
                // cout << "car num : " << a << '\n';
                result++;
                out.pop();
                idx[a] = 0;
                // cout << "idx[a] : " << idx[a] << '\n';
            }
        }
    }
    cout << result << endl;
}
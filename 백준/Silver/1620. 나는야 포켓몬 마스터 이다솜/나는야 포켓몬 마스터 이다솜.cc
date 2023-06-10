#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int N,M;

string name[100001]; // 해당 번호에 이름 저장해놓음

map<string, int> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        string s;
        cin >> s;
        name[i] = s; //-> 해당 번호에 이름을 입력
        m.insert(make_pair(s,i));
    }
    
    
    for(int i = 1; i<=M; i++){
        string s;
        int n;
        cin >> s;
        //숫자가 입력됐는지 확인 !!!!!!! 중요
        //문자열 자체는 입력이 안되므로..첫번째 인덱스, char를 빼서 넣음
        if(isdigit(s[0]) == true){
            n = stoi(s); // string to int
            cout << name[n] << '\n';
        }else{
            auto it = m.find(s);
            cout << it->second << '\n';
        }
    }
}
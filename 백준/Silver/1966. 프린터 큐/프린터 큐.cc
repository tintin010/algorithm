#include <iostream>
#include <queue>

using namespace std;

int main(){
    int tt;
    cin >> tt;

    for(int first = 0; first < tt; first++){
        int cnt, idx;
        cin >> cnt >> idx;
        int imp[10];
        int high = 0;
        int count = 0;
        queue <int> q;
        queue <int> follow;
        for(int i = 0; i < 10; i++) imp[i] = 0;
        // cout << cnt << '\n';
        for(int i = 0; i < cnt; i++){
            int temp;
            cin >> temp;
            // cout << temp << '\n';
            q.push(temp);
            if(idx == i) follow.push(1);
            else follow.push(0);
            imp[temp]++;
            if(temp > high) high = temp;
        }
        // cout << "high : " << high << '\n';
        while(true){
            // cout << q.front() << '\n';
            
            if(q.front() == high){
                // cout << "front : " << q.front() << " || high : " << high << '\n';
                if(follow.front() == 1){
                    cout << count + 1 << '\n';
                    break;
                }else{
                    count ++;
                    imp[q.front()]--;   //  중요도 관리
                    // cout << "imp[q.front()] : " << imp[q.front()] << '\n';
                    if(imp[q.front()] <= 0){
                        int down = q.front();
                        while(true){
                            down -= 1;
                            if(imp[down] > 0){
                                // cout << "down : " << down << '\n';
                                high = down;
                                break;
                            }
                        }
                    }
                    follow.pop();   // 추적 관리
                }
                q.pop();    //실질적 큐 관리
            }else{
                // cout << "front : " << q.front() << " || high : " << high << '\n';
                //큐의 우선순위가 최상위가 아니므로 뒤로 보냄냄
                q.push(q.front());
                q.pop();
                //추적도 큐를 따라줌
                follow.push(follow.front());
                follow.pop();
            }
        }
    }
}
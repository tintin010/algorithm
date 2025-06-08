#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    queue <pair<int, int>> q; /** pair<spot, cnt> **/ 
    int visit[100001];
    fill_n(visit, 100001, 0);
    q.push({n, 0});
    visit[n] = 1;

    while(!q.empty()){
        int spot = q.front().first;
        int cnt = q.front().second;
        
        q.pop();

        if(spot == k){
            cout << cnt << '\n';
            return 0;
        }

        if(spot - 1 == k){
            cout << cnt + 1 << '\n';
            return 0;
        }else if(spot - 1 > 0 && visit[spot - 1] == 0){
            visit[spot - 1] = 1;
            q.push({spot - 1, cnt + 1});
        }

        if(spot * 2 == k){
            cout << cnt + 1 << '\n';
            return 0;
        }else if(spot * 2 < 100001 && visit[spot * 2] == 0){
            visit[spot * 2] = 1;
            q.push({spot * 2, cnt + 1});
        }

        if(spot + 1 == k){
            cout << cnt + 1 << '\n';
            return 0;
        }else if(spot + 1 < 100001 && visit[spot + 1] == 0){
            visit[spot + 1] = 1;
            q.push({spot + 1, cnt + 1}); 
        }

    }
    return 0;
}
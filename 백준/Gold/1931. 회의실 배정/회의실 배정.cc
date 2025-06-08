#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<pair<int, int>> sch;
    cin >>n;
    for(int i = 0; i < n; i++){
        int st, ed;
        cin >>st >> ed;
        sch.push_back({ed, st});
    }

    sort(sch.begin(), sch.end());

    int room = sch[0].first;
    int result = 1;

    for(int i = 1; i < n; i++){
        if(room <= sch[i].second){
            room = sch[i].first;
            result++;
        }
    }

    cout << result << '\n';

}
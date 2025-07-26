#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (){
    int testcase;
    int n;

    cin >> testcase;

    for(int i = 0; i < testcase; i++){

        cin >> n;

        vector<pair<int,int>> grades;
        
        for(int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            grades.push_back({x,y});
        }

        sort(grades.begin(), grades.end());

        int t = 0;
        int ans = 1;

        for(int j = 1; j < n; j++) {
            if(grades[t].second > grades[j].second) {
                ans++;
                t = j;
            }
        }
        cout << ans << '\n';
        
    }
}
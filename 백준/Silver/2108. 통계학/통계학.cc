#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    int arr[8001];
    vector<int> v;
    int mini = 4001;
    int maxi = -4001;
    double sum = 0;

    for(int i = 0; i < 8001; i++) arr[i] = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
        sum += t;
        arr[t + 4000]++;
        mini = min(mini, t);
        maxi = max(maxi, t);
    }
    sort(v.begin(), v.end());

    int laa = 0;
    int ans;
    for(int i = 0; i < 8001; i++){
        if(arr[i] > laa){
            laa = arr[i];
        }
    }
    int flag = 0;
    for(int i = 0; i < 8001; i++){
        if(arr[i] == laa){
            flag++;
            if(flag == 2){
                ans = i - 4000;
                break;
            }
            ans = i - 4000;
        }
    }

    double avg = round(sum / (double)n);
    if(avg == -0) avg = 0;
    

    cout << avg << '\n';
    cout << v[n / 2] << '\n';
    cout << ans << '\n';
    cout << maxi - mini << '\n';
    return 0;

}
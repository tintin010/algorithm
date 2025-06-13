#include <iostream>

using namespace std;

int main(){
    long long tree[10001];
    int k, n;
    int result = 0;
    cin >> k >> n;
    for(int i = 0; i < k; i++) tree[i] = 0;
    long long min = 1, max = 0;

    for(int i = 0; i < k; i++){
        long long l;
        cin >> l;
        tree[i] = l;
        if(max < l) max = l;
    }

    while(min <= max){
        long long mid = (min + max) / 2;
        int temp = 0;
        for(int i = 0; i < k; i++) temp += tree[i] / mid;
        if(temp >= n){
            min = mid + 1;
            result = mid;
        }else{
            max = mid - 1;
        }
    }
    cout << result << '\n';
}
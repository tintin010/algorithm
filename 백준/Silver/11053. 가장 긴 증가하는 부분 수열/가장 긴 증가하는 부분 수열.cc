#include <iostream>

using namespace std;

int main(){

    int n;
    int arr[1001];
    int ans[1001];
    int fin = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) ans[i] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        fin = max(fin, ans[i]);
    }
    
    cout << fin << '\n';
    return 0;
}
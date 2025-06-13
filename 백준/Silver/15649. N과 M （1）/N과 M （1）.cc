#include <iostream>

using namespace std;

int arr[9];
int res[9];
int n, m;

void calc(int a){
    if(a == m){
        for(int i = 0; i < m; i++) cout << res[i] << " ";
        cout << '\n';
    }else{
        for(int i = 1; i <= n; i++){
            if(arr[i] == 0){
                arr[i] = 1;
                res[a] = i;
                calc(a + 1);
                arr[i] = 0;
            }
        }
    }
}

int main(){

    cin >> n >> m;
    for(int i = 1; i < 9; i++){
        arr[i] = 0;
        res[i] = 0;
    }
    calc(0);
}
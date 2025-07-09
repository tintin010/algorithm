#include <iostream>

using namespace std;

int arr[3000][3000];
int n;
int ans[3];

void cut(int x, int y, int a){
    


    int t = arr[x][y];
    int flag = 1;
    
    for(int i = x; i < x + a; i++){
        for(int j = y; j < y + a; j++){
            if(t != arr[i][j]){
                flag = 0;
            }
            if(flag == 0){
                int d = a / 3;

                cut(x, y, d);
                cut(x, y + d, d);
                cut(x + d, y, d);
                cut(x + d, y + d, d);
                cut(x + d, y + 2 * d, d);
                cut(x + 2 * d, y + d, d);
                cut(x + 2 * d, y, d);
                cut(x, y + 2 * d, d);
                cut(x + 2 * d, y + 2 * d, d);
                return;
            }
        }
    }

    if(t == -1) ans[0]++;
    else if(t == 0) ans[1]++;
    else if(t == 1) ans[2]++;

    return;
}

int main(){

    for(int i = 0; i < 3; i++) ans[i] = 0;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k;
            cin >> k;
            arr[i][j] = k;   
        }
    }

    cut(0, 0, n);

    for(int i = 0; i < 3; i++)
        cout << ans[i] << "\n";
    
    return 0;

}
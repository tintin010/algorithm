#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long dis[100000];
    long long price[100000];

    for(int i = 0; i < n; i++){
        dis[i] = 0;
        price[i] = 0;
    }

    for(int i = 0; i < n - 1; i++) cin >> dis[i];
    for(int i = 0; i < n; i++) cin >> price[i];

    long long ans = 0;
    long long tp = price[0];
    for(int i = 0; i < n - 1; i++){
        if(tp <= price[i + 1]){
            ans += tp * dis[i];
            continue;
        }
        else{
            ans += tp * dis[i];
            tp = price[i + 1];
        }
    }
    cout << ans << '\n';
    return 0;

}
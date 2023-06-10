//11659 구간 합 구하기4

#include<iostream>

using namespace std;

int N,M;
int map[100001];
int dp[100001];

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 1; i<=N; i++){
        int a;
        cin >> a;
        map[i] = a;
        dp[i] = a+dp[i-1];
    }
    
    while(M--){
        int a,b;
        cin >> a >> b;
        
        cout << dp[b]-dp[a-1] << '\n';
    }
}
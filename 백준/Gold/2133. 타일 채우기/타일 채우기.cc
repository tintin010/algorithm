//2133 타일 채우기 -RE-

//매번 생기는 2개의 고유 모양을 체크
#include <iostream>

using namespace std;
int n;
int dp[31];

int main() {
	//i가 2씩 증가할 때마다 고유의 모양이 2개씩 생성됨
	//F[N] = ( F[N - 2] * F[2] ) + ( F[N - 4] * 2 ) ...+ ( F[0] * 2 )
	cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	cout << dp[n] << endl;
}
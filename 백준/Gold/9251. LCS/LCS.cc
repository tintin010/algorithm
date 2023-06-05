//9251 LCS
#include <iostream>

using namespace std;
string input;
string s1, s2;
char arr[1001][1001];
int dp[1001][1001];

int main() {
	cin >> s1;
	for (int i = 0; i <= s1.length(); i++) arr[i][0] = 0;
	cin >> s2;
	for (int i = 0; i <= s2.length(); i++) arr[0][i] = 0;

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[s1.length()][s2.length()] << endl;
}
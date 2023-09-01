//12865 평범한 배낭
#include <iostream>
#include <algorithm>

using namespace std;

int stuff, kg;
int weight[101];
int value[101];
int arr[101][100001];


int main()
{
	cin >> stuff >> kg;
	for (int i = 1; i <= stuff; i++) cin >> weight[i] >> value[i];
	int result = 0;
	for (int i = 1; i <= stuff; i++) {
		for (int j = 1; j <= kg; j++) {
			if (weight[i] > j) {
				arr[i][j] = arr[i - 1][j];
			}
			else {
				arr[i][j] = max(arr[i - 1][j - weight[i]] + value[i], arr[i - 1][j]);
			}
		}
	}
	cout << arr[stuff][kg] << endl;

}
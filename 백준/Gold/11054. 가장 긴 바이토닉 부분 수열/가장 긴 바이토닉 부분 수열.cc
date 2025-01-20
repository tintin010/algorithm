//가장 긴 바이토닉 부분 수열 11054

#include <iostream>
#include <algorithm>

using namespace std;
int len;
int list[1001];
int arr[1001];
int r_arr[1001];



int main()
{
	cin >> len;
	for (int i = 1; i <= len; i++) cin >> list[i];
	
	for (int i = 1; i <= len; i++) {
		arr[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (list[j] < list[i] && arr[i] < arr[j] + 1) {
				arr[i] = arr[j] + 1;
				//cout << "i : " << i << " arr[i] : " << arr[i] << endl;
			}
		}
	}
	for (int i = len; i >=1 ; i--) {
		r_arr[i] = 1;
		for (int j = len; j >= i; j--) {
			if (list[j] < list[i] && r_arr[i] < r_arr[j] + 1) {
				r_arr[i] = r_arr[j] + 1;
			}
		}
	}
	int res = -1;
	for (int i = 1; i <= len; i++) res = max(res, arr[i] + r_arr[i] - 1);
	cout << res << endl;

}
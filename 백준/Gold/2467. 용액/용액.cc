//두 용액 2470

#include <iostream>
#include <algorithm>

using namespace std;
long long cnt = 0;
long long  arr[100001];

int main() {
	cin >> cnt;
	for (int i = 0; i < cnt; i++) cin >> arr[i];

	sort(arr, arr + cnt);
	//cout << arr[0] << endl;

	long long mini = 2000000000;
	long long st = 0, ed = cnt - 1;
	long long temp = 0;
	long long fs = 0, fd = 0;
	while (st < ed) {
		temp = arr[st] + arr[ed];
		if (abs(temp) < mini) {
			mini = abs(temp);
			fs = st;
			fd = ed;
			
		}
		if (temp > 0)ed--;
		else st++;
	}
	//cout << "fd : " << fd << endl;
	cout << arr[fs] << " " << arr[fd] << endl;
}
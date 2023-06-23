//17626 Four Squares

#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;
int a;
int arr[50001];

int main() {
	cin >> a;
	for (int i = 1; i <= a; i++) {
		arr[i] = arr[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	cout << arr[a] << endl;
}
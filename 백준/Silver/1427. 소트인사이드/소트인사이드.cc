#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string n;
    cin >> n;

    vector <int> arr;

    for(int i = 0; i < n.length(); i++){
        arr.push_back(n[i] - '0');
    }

    for(int i = 0; i < n.length(); i++){
        for(int j = i + 1; j < n.length(); j++){
            if(arr[j] > arr[i]){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    for(int i = 0; i < n.length(); i++) cout << arr[i];
    return 0;
}
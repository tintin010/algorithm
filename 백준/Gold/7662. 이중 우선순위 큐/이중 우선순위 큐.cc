#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        multiset<int> numbers;

        while (n--) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') {
                numbers.insert(num);
            } else if (op == 'D') {
                if (!numbers.empty()) {
                    if (num == -1) {
                        numbers.erase(numbers.begin());
                    } else if (num == 1) {
                        auto it = numbers.end();
                        it--;
                        numbers.erase(it);
                    }
                }
            }
        }

        if (numbers.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *numbers.rbegin() << " " << *numbers.begin() << "\n";
        }
    }

    return 0;
}

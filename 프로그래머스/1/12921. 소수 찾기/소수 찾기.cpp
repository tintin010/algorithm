#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> primes(n + 1, true);
    
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            ++answer;
        }
    }
    
    return answer;
}
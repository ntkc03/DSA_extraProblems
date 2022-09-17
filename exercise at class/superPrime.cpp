#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    queue<int> prime;
    prime.push(2);
    prime.push(3);
    prime.push(5);
    prime.push(7);
    while(prime.front() <= n) {
        int tmp = prime.front();
        for(int i = 1; i <= 9; i += 2) {
            int num = tmp * 10 + i;
            if(isPrime(num)) {
                prime.push(num);
            }
        }
        cout << tmp << " ";
        prime.pop();
    }
    return 0;
}

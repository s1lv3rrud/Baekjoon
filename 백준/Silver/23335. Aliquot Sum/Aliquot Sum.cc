#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    stringstream ss;

    while (t--) {
        int n;
        scanf("%d", &n);

        int sum = (n > 1) ? 1 : 0;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i * i != n) {
                    sum += n / i;
                }
            }
        }

        if (sum > n) ss << "abundant\n";
        else if (sum < n) ss << "deficient\n";
        else ss << "perfect\n";
    }

    // Print all results at once
    cout << ss.str();

    return 0;
}
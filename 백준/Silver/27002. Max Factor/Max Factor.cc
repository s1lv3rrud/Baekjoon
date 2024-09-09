#include <bits/stdc++.h>
using namespace std;

int largestPrimeFactor(int n) {
    int largest = 1;
    
    // Handle 2 as a special case
    while (n % 2 == 0) {
        largest = 2;
        n = n / 2;
    }
    
    // Check for odd prime factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n = n / i;
        }
    }
    
    // If n is still greater than 2, it is prime itself
    if (n > 2)
        largest = n;
    
    return largest;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int maxPrimeFactor = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int primeFactor = largestPrimeFactor(num);
        
        if (primeFactor > maxPrimeFactor || (primeFactor == maxPrimeFactor && num > ans)) {
            maxPrimeFactor = primeFactor;
            ans = num;
        }
    }

    cout << ans << endl;

    return 0;
}
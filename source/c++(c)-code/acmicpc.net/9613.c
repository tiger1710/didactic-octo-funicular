#include <stdio.h>

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long gcdfor(long long a, long long b) {
    long long min = a < b ? a : b;
    long long ans;
    for (long long i = 1; i <= min; i++) {
        if ((a % i) == 0 && (b % i) == 0) {
            ans = i;
        }
    }
    return ans;
}

int main(void) {
    int t; scanf("%d", &t);
    int arr[100];
    while (t--) {
        int n; scanf("%d", &n);
        long long sum = 0;

        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);

        for (int i = 0; i < n; i++)
            for (int k = i + 1; k < n; k++)
                sum += gcdfor(arr[i], arr[k]);
        
        printf("%lld\n", sum);
    }
    


    return 0;
}
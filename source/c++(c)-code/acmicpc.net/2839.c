#include <stdio.h>

int main(void) {
    int N; scanf("%d", &N);
    int ans = 123456789;

    int sugar;
    for (int i = 0; i * 5 <= N; i++) {
        sugar = N - (i * 5);
        int three = sugar / 3;
        int reminder = sugar % 3;
        if (reminder == 0) {
            ans = ans < (i + three) ? ans : (i + three);
        }
    }
    if (ans == 123456789)
        puts("-1");
    else printf("%d\n", ans);
    
    return 0;
}
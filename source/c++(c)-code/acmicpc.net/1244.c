#include <stdio.h>

void male(int switches[], int n, int pos) {
    for (int i = pos; i <= n; i += pos)
        switches[i] = !switches[i];
}

void female(int switches[], int n, int pos) {
    switches[pos] = !switches[pos];
    for (int l = pos - 1, r = pos + 1; 0 <= l && r <= n; l--, r++) {
        if (switches[l] != switches[r]) break;
        switches[l] = !switches[l];
        switches[r] = !switches[r];
    }
}

int main(void) {
    int n; scanf("%d", &n);
    int switches[101];
    for (int i = 1; i <= n; i++) {
        scanf("%d", switches + i);
    }

    int studentCnt; scanf("%d", &studentCnt);

    while (studentCnt--) {
        int gender, pos; scanf("%d %d", &gender, &pos);
        switch (gender) {
        case 1:
            male(switches, n, pos);
            break;
        case 2:
            female(switches, n, pos);
            break;
        default:
            break;
        }
    }

    for (int i = 1; i < n; i++)
        printf("%d ", switches[i]);
    puts("");

    return 0;
}


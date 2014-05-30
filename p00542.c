#include <stdio.h>

char names[16][11];
double direct_probs[16][16];
double prev_probs[16], probs[16];

int
main()
{
    double p;
    int i, j;

    for (i = 0; i < 16; i++)
        scanf("%s", &names[i]);

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            scanf("%lf", &p);
            direct_probs[i][j] = p / 100.0;
        }
    }

    for (i = 0; i < 16; i++) {
        probs[i] = direct_probs[i][i ^ 01];
    }

    for (i = 0; i < 16; i++)
        prev_probs[i] = probs[i];

    for (i = 0; i < 16; i++) {
        p = 0.0;
        for (j = 02; j <= 03; j++)
            p += prev_probs[i^j] * direct_probs[i][i^j];
        probs[i] = prev_probs[i] * p;
    }

    for (i = 0; i < 16; i++)
        prev_probs[i] = probs[i];

    for (i = 0; i < 16; i++) {
        p = 0.0;
        for (j = 04; j <= 07; j++)
            p += prev_probs[i^j] * direct_probs[i][i^j];
        probs[i] = prev_probs[i] * p;
    }

    for (i = 0; i < 16; i++)
        prev_probs[i] = probs[i];

    for (i = 0; i < 16; i++) {
        p = 0.0;
        for (j = 010; j <= 017; j++)
            p += prev_probs[i^j] * direct_probs[i][i^j];
        probs[i] = prev_probs[i] * p;
    }

    for (i = 0; i < 16; i++) {
        printf("%-10s p=%1.2lf%%\n", names[i], probs[i] * 100.0);
    }

    return 0;
}


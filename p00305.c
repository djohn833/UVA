#include <stdio.h>

int k;
int result[14] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

int
main(void)
{
    while (scanf("%d", &k) && k != 0) {
        printf("%d\n", result[k]);
    }

    return 0;
}


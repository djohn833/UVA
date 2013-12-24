#include <ctype.h>
#include <stdio.h>

void
print_binary(int n, int width)
{
    int i;
    for (i = width-1; i >= 0; i--)
        putchar((n & (1<<i)) ? '1' : '0');
}

int
main(void)
{
    int num_cases, caseno;
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        int i, x, y, z;
        char op;

        scanf("%x %c %x", &x, &op, &y);

        if (op == '+')
            z = x + y;
        else
            z = x - y;

        print_binary(x, 13);
        printf(" %c ", op);
        print_binary(y, 13);
        printf(" = %d\n", z);
    }

    return 0;
}

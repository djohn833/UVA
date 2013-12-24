#include <stdio.h>
#include <string.h>

int caseno, num_cases;

int last_tbl[200];
#define last_val(n) last_tbl[(n) + 100]

int
main()
{
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        int i, k, max, min, len, vals[50], val;
        char line[80], out[80];
        scanf("%s", line);
        len = strlen(line);

        max = -2000;
        min = 2000;
        val = 0;
        for (i = 0; i < len; i++) {
            if (line[i] == 'R') {
                vals[i] = val++;
                out[i] = '/';
            } else if (line[i] == 'F') {
                vals[i] = --val;
                out[i] = '\\';
            } else {
                vals[i] = val;
                out[i] = '_';
            }

            if (vals[i] > max)
                max = vals[i];
            if (vals[i] < min)
                min = vals[i];
            last_val(vals[i]) = i;
        }

        printf("Case #%d:\n", caseno);

        for (k = max; k >= min; k--) {
            printf("| ");
            for (i = 0; i < len; i++) {
                if (vals[i] == k)
                    putchar(out[i]);
                else if (i < last_val(k))
                    putchar(' ');
            }
            printf("\n");
        }

        putchar('+');
        for (i = 0; i < len+2; i++) {
            putchar('-');
        }

        putchar('\n');
        putchar('\n');
    }

    return 0;
}

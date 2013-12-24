#include <stdio.h>
#include <string.h>

int caseno, num_cases;
int N;

void
indent(int n)
{
    int i;
    for (i = 0; i < n; i++)
        putchar(' ');
}

int sort[9], used[8];
int pos;

void
print_loops(int level)
{
    int i, k, m, t;

    for (i = 0; i < level; i++) {
        if (level > 1) {
            indent(2 * (level-1));

            if (i < level-1) {
                if (i == 0)
                    printf("if");
                else
                    printf("else if");


                printf(" %c < %c then\n", sort[0] + 'a', sort[1] + 'a');
            } else
                printf("else\n");
        }

        if (level == N) {
            indent(2 * N);
            printf("writeln(%c", sort[0] + 'a');
            for (k = 1; k < N; k++)
                printf(",%c", sort[k] + 'a');
            printf(")\n");

            t = sort[pos];
            sort[pos] = sort[(pos-1+N) % N];
            sort[(pos-1+N) % N] = t;
            pos = (pos-1+N) % N;
        } else {
            print_loops(level + 1);
        }
    }
}

void
nested_loop(int depth, int num_loops)
{
    int i, k;

    for (i = 0; i < N; i++) {
        if (!used[i]) {
            sort[depth] = i;
            used[i] = 1;

            if (depth == num_loops) {
                indent(2 + 2*N);
                printf("writeln(%c", sort[1] + 'a');
                for (k = 2; k <= N; k++)
                    printf(",%c", sort[k] + 'a');
                printf(")\n");
            } else {
                nested_loop(depth + 1, num_loops);
            }

            used[i] = 0;
        }
    }
}


int
main()
{
    int k;

    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        if (caseno > 1)
            putchar('\n');

        scanf("%d", &N);

        printf("program sort(input,output);\n");
        printf("var\n");
        printf("a");
        for (k = 1; k < N; k++)
            printf(",%c", k + 'a');
        printf(" : integer;\n");
        printf("begin\n");

        indent(2);
        printf("readln(a");
        for (k = 1; k < N; k++)
            printf(",%c", k + 'a');
        printf(");\n");

        for (k = 0; k < N; k++)
            sort[k] = k;
        nested_loop(1, N);
        //pos = N - 1;
        //print_loops(1);

        printf("end.\n");
    }

    return 0;
}

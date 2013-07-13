#include <stdio.h>

int caseno, num_cases;
int N, mile, juice;

int
main()
{
    int i, dur;
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        scanf("%d", &N);
        mile = juice = 0;

        for (i = 0; i < N; i++) {
            scanf("%d", &dur);
            mile += ((dur+30) / 30) * 10;
            juice += ((dur+60) / 60) * 15;
        }

        printf("Case %d: ", caseno);
        if (mile < juice)
            printf("Mile %d\n", mile);
        else if (juice < mile)
            printf("Juice %d\n", juice);
        else
            printf("Mile Juice %d\n", mile);
    }

    return 0;
}

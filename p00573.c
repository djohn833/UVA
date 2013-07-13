#include <stdio.h>

int H, U, D, F;
int day;
double height;

int
main()
{
    while (scanf("%d %d %d %d", &H, &U, &D, &F) == 4 && H != 0) {
        height = 0.0;

        for (day = 1; ; day++) {
            double climb = (U - (day-1)*(F/100.0)*U);
            if (climb > 0.0)
                height += climb;
            if (height > H)
                goto success;
            else if (height < 0.0)
                goto failed;

            height -= D;
            if (height > H)
                goto success;
            else if (height < 0.0)
                goto failed;
        }

success:
        printf("success on day %d\n", day);
        continue;
failed:
        printf("failure on day %d\n", day);
        continue;
    }

    return 0;
}

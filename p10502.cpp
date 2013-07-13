#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int rows, cols;
char grid[100][100];
int rsums[100][100], csums[100][100];

int
main()
{
    int i, j, k, n;

    while (cin >> rows && rows != 0) {
        cin >> cols;

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '1') {
                    rsums[i][j] = csums[i][j] = 1;
                    for (k = i-1; k >= 0 && grid[k][j] == '1'; k--)
                        rsums[k][j]++;
                    for (k = j-1; k >= 0 && grid[i][k] == '1'; k--)
                        csums[i][k]++;
                }
            }
        }

        printf("row sums:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++)
                printf("%d,", rsums[i][j]);
            putchar('\n');
        }

        printf("col sums:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++)
                printf("%d,", csums[i][j]);
            putchar('\n');
        }

        n = 0;
        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                n += rsums[i][j] * csums[i][j];

        printf("%d\n", n);
    }

    return 0;
}

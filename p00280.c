#include <stdio.h>
#include <string.h>

int visited[101];
int adj[101][101];
int n, num_reached;

void
scan(int v)
{
    int i;

    for (i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            num_reached++;
            visited[i] = 1;
            scan(i);
        }
    }
}

int
main()
{
    int i, j, k, p;

    while (scanf("%d", &n) == 1 && n != 0) {
        memset(adj, 0, sizeof(adj));

        while (scanf("%d", &i) == 1 && i != 0) {
            while (scanf("%d", &j) == 1 && j != 0) {
                adj[i][j] = 1;
            }
        }

        scanf("%d", &k);
        for (i = 0; i < k; i++) {
            scanf("%d", &j);

            num_reached = 0;
            memset(visited, 0, sizeof(visited));
            scan(j);

            printf("%d", n - num_reached);

            for (p = 1; p <= n; p++)
                if (!visited[p])
                    printf(" %d", p);
            putchar('\n');
        }
    }

    return 0;
}

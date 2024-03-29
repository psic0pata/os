#include<stdio.h>


void main() {
    int work[5], avl[5], alloc[10][10], l;
    int need[10][10], n, m, I, j, avail[10], max[10][10], k, count, i, fcount = 0, pr[10];
    char finish[10] = {'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f'};

    printf("\n enter the no of processes: ");
    scanf("%d", &n);
    printf("\n enter the no of resources: ");
    scanf("%d", &m);
    printf("\n enter the total no of resources: ");
    for(i = 1; i <= m; i++)
        scanf("%d", &avail[i]);
    printf("\n enter the max resources required by each process in allocation matrix: ");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            scanf("%d", &max[i][j]);
    printf("\n process allocation matrix: ");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            scanf("%d", &alloc[i][j]);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i = 1; i <= n; i++) {
        k = 0;
        for(j = 1; j <= m; j++) {
            k = k + alloc[i][j];
        }
        avl[i] = avl[i] - k;
        work[i] = avl[i];
    }

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++) {
            count = 0;
            for(j = 1; j <= m; j++) {
                if((finish[i] == 'f') && (need[i][j] <= work[i]))
                    count++;
            }
            if(count == m) {
                for(l = 1; l <= m; l++)
                    work[l] = work[l] + alloc[i][l];
                finish[i] = 't';
                pr[k] = i;
                break;
            }
        }

    for(i = 1; i <= n; i++)
        if(finish[i] == 't')
            fcount++;
    if(fcount == n) {
        // Safe state
    }
    else
        printf("\n the system is not in safe state");

    for(i = 1; i <= n; i++)
        printf("\n %d", pr[i]);

    //getch();
}


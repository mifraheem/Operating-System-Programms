#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tt;
    int prior;
};

int main()
{
    struct process p[10], temp;
    int i, j, n, totwt = 0, tottt = 0;
    float arg1, arg2;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        p[i].pid = i;
        printf("\nEnter the burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
        printf("Enter the priority for process %d: ", i);
        scanf("%d", &p[i].prior);
    }

    // Sorting processes by priority in descending order
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (p[i].prior < p[j].prior)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[1].wt = 0;
    p[1].tt = p[1].bt;

    for (i = 2; i <= n; i++)
    {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
    }

    printf("\nProcess ID\tBT\tWT\tTT\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t%ds\t%ds\t%ds\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    arg1 = (float)totwt / n;
    arg2 = (float)tottt / n;

    printf("\nAverage WT = %.2fs\tAverage TT = %.2fs\n", arg1, arg2);

    // Use getchar() to wait for user input
    printf("Press Enter to exit...");
    getchar();

    return 0;
}

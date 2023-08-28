#include <stdio.h>
struct process
{
    int pid;
    int bt;
    int wt;
    int tt;
} p[10], temp;

int main()
{
    int i, j, n, totwt = 0, tottt = 0;
    float avg1, avg2;


    printf("\nEnter the number of processes:\t");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
        p[i].pid = i;
        printf("\nEnter the burst time for process %d:\t", i);
        scanf("%d", &p[i].bt);
    }
    
    // Implementing Shortest Job First (SJF) algorithm
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                // Swap process data
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;
    i = 2;
    
    while (i <= n)
    {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
        i++;
    }
    
    printf("\nProcess id\tbt\twt\ttt");
    for (i = 1; i <= n; i++)
    {
        printf("\n%d\t\t%d\t%d\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
    }
    
    avg1 = (float)totwt / n;
    avg2 = (float)tottt / n;
    printf("\nAVG1=%f\t AVG2=%f", avg1, avg2);
    
    getchar();
    return 0;
}

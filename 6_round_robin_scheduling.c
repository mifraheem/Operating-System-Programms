
#include <stdio.h>
// #include<conio.h>
struct process {
    int pid, bt, tt, wt;
};
int main() {
    struct process x[10], p[30];
    int i, j, k, tot = 0, m, n;
    float wttime = 0.0, tottime = 0.0, a1, a2;
 
    printf("\nEnter the number of process: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        x[i].pid = i;
        printf("\nEnter the Burst Time: ");
        scanf("%d", &x[i].bt);
        tot = tot + x[i].bt;
    }

    printf("\nTotal Burst Time:\t%d", tot);
    p[0].tt = 0;
    k = 1;

    printf("\nEnter the Time Slice: ");
    scanf("%d", &m);
    for (j = 1; j <= tot; j++) {
        for (i = 1; i <= n; i++) {
            if (x[i].bt != 0) {
                p[k].pid = i;
                if (x[i].bt - m < 0) {
                    p[k].wt = p[k - 1].tt;
                    p[k].bt = x[i].bt;
                    p[k].tt = p[k].wt + x[i].bt;
                    x[i].bt = 0;
                    k++;
                }
                else
                {

                    p[k].wt = p[k - 1].tt;

                    p[k].tt = p[k].wt + m;

                    x[i].bt = x[i].bt - m;
                    k++;
                }
            }
        }
    }

    printf("\nProcess id \twt \ttt");
    for (i = 1; i < k; i++)
    {
        printf("\n\t%d \t%d \t%d", p[i].pid, p[i].wt, p[i].tt);
        wttime = wttime + p[i].wt;
        tottime = tottime + p[i].tt;
        a1 = wttime / n;
        a2 = tottime / n;
    }

    printf("\n\nAverage Waiting Time:\t%f", a1);
    printf("\n\nAverage TurnAround Time:\t%f", a2);
    return 0;
}

#include <stdio.h>

struct process {
    int pid;
    int bt;
    int wt, tt;
} p[10];

int main() {
    int i, n, totwt, tottt, avg1, avg2;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        p[i].pid = i;
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;
    i = 2;

    while (i <= n) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
        i++;
    }

    totwt = tottt = 0;

    printf("\nProcess ID\tBT\tWT\tTT\n");

    for (i = 1; i <= n; i++) {
        printf("%d\t\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    avg1 = totwt / n;
    avg2 = tottt / n;
    printf("\nAverage WT = %d\tAverage TT = %d\n", avg1, avg2);
    
    // Use getchar() to wait for user input
    printf("Press Enter to exit...");
    getchar(); // This will wait for the user to press Enter

    return 0;
}

#include <stdio.h>
// #include <conio.h>
int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[10], optcal[50], count = 0;
int optvictim();
void main()
{
    // clrscr();
    printf("\n OPTIMAL PAGE REPLACEMENT ALGORITHN");
    printf("\n ................................. ");
    printf("\nEnter the no.of frames");
    scanf("%d", &nof);
    printf("Enter the no.of reference string");
    scanf("%d", &nor);
    printf("Enter the reference string");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);
    // clrscr();
    printf("\n OPTIMAL PAGE REPLACEMENT ALGORITHM");
    printf("\n ............................... ");
    printf("\nThe given string");
    printf("\n ................... \n");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);
    for (i = 0; i < nof; i++)
    {
        frm[i] = -1;
        
                    optcal[i] = 0;
    }
    for (i = 0; i < 10; i++)
        recent[i] = 0;
    printf("\n");
    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("\n\tref no %d ->\t", ref[i]);
        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            count++;
            if (count <= nof)
                victim++;
            else
                victim = optvictim(i);
            pf++;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
        
    }
    printf("\n Number of page faults: %d", pf);
    // getch();
}
int optvictim(int index)
{
    int i, j, temp, notfound;
    for (i = 0; i < nof; i++)
    {
        notfound = 1;
        for (j = index; j < nor; j++)
            if (frm[i] == ref[j])
            {
                notfound = 0;
                optcal[i] = j;
                break;
            }
        if (notfound == 1)
            return i;
    }}
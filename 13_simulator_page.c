#include <stdio.h>
// #include <conio.h>
int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[10], lrucal[50], count = 0;
int lruvictim();
void main()
{
    // clrscr();
    printf("\n\t\t\t LRU PAGE REPLACEMENT ALGORITHM");
    printf("\n Enter no.of Frames ... ");
    scanf("%d", &nof);
    printf(" Enter no.of reference string..");
    scanf("%d", &nor);
    printf("\n Enter reference string..");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);
    printf("\n\n\t\t LRU PAGE REPLACEMENT ALGORITHM ");
    printf("\n\t The given reference string:");
    printf("\n ............. ");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);
    for (i = 1; i <= nof; i++)
    {
        frm[i] = -1;
        lrucal[i] = 0;
    }
    for (i = 0; i < 10; i++)

        recent[i] = 0;
    printf("\n");
    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("\n\t Reference NO %d->\t", ref[i]);
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
                victim = lruvictim();
            pf++;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
        recent[ref[i]] = i;
    }
    printf("\n\n\t No.of page faults...%d", pf);
    // getch();
}
int lruvictim()
{
    int i, j, temp1, temp2;
    for (i = 0; i < nof; i++)
    {
        temp1 = frm[i];
        lrucal[i] = recent[temp1];
    }
    temp2 = lrucal[0];
    for (j = 1; j < nof; j++)
    {
        if (temp2 > lrucal[j])
            temp2 = lrucal[j];
    }
    for (i = 0; i < nof; i++)
        if (ref[temp2] == frm[i])
            return i;
    return 0;
}